#include "mydb.h"

SingletonMyDB* SingletonMyDB::p_instance;
SingletonDestroyerMyDB SingletonMyDB::destroyer;

void SingletonMyDB::_init()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("TestDSN");
    qDebug() << db.databaseName();
    db.setUserName("root");
    db.setPassword("12345");

    bool ok = db.open();
    bool res;

    if(!ok)
        return;

    QSqlQuery query(db);

    qDebug() << "Creating DB...";
    res = query.exec("create database omagad;");
    qDebug() << res;

    if (!res)
    {
        qDebug() << "DB with that name already exists";
        qDebug() << "Deleting already existing DB... " << query.exec("drop database omagad;");
        qDebug() << "Creating DB again... " << query.exec("create database omagad;");
    }
    qDebug() << "Using DB... " << query.exec("use omagad;");
    //создали таблицу
    qDebug() << "Creating table USER(login, password, email, task_number, variant, answer).... "
             << query.exec("CREATE TABLE USER("
                            "login VARCHAR(20) NOT NULL unique, "
                            "password VARCHAR(20) NOT NULL, "
                            "email VARCHAR(30) NOT NULL unique, "
                            "task_number INT NOT NULL,"
                            "variant INT NOT NULL,"
                            "answer TEXT NOT NULL);"
                            );

    query.prepare("INSERT INTO USER(login, password, email, task_number, variant, answer) "
                  "VALUES ('admin', '123', 'admin@mail.ru', '3', '6', '21')");
    qDebug() << "Insert USER(admin, 123, admin@mail.ru, 3, 6, 21)... " << query.exec();// выполнить запрос

    query.prepare("INSERT INTO USER(login, password, email, task_number, variant, answer) "
                  "VALUES ('user', '123', 'user@mail.ru', '0', '3', '-4');");
    qDebug() << "Insert USER(user, 123, user@mail.ru, 0, 3, -4)... " << query.exec();// выполнить запрос

    db.close();
}

bool SingletonMyDB::isReg(QString login)
{
    db.open();
    QSqlQuery query(db);
    query.exec("use omagad;");

    QString q = "SELECT * FROM USER WHERE LOGIN = '" + login + "';";
    query.exec(q);

    bool res = (query.next()) ? true : false;

    db.close();

    return res;
}

bool SingletonMyDB::isMailAvailable(QString mail)
{
    db.open();
    QSqlQuery query(db);
    query.exec("use omagad;");

    QString q = "SELECT * FROM USER WHERE EMAIL = '" + mail + "';";
    query.exec(q);

    bool res = (query.next()) ? true : false;

    db.close();

    return !res;
}

bool SingletonMyDB::Register(QStringList params)
{
    if(isReg(params.at(0)))
        return false;
    if(!isMailAvailable(params.at(2)))
        return false;
    db.open();
    QSqlQuery query(db);
    query.exec("use omagad;");

    query.prepare("INSERT INTO USER(login, password, email, task_number, variant, answer) "
                  "VALUES ('" + params.at(0) + "', '" + params.at(1) + "', '" + params.at(2) + "', '0', '0', '0');");
    bool res = query.exec();

    db.close();

    return res;
}

bool SingletonMyDB::Auth(QStringList params)
{
    if(!isReg(params.at(0)))
        return false;

    db.open();
    QSqlQuery query(db);
    query.exec("use omagad");

    query.prepare("SELECT * FROM USER WHERE "
                  "login = '" + params.at(0) + "' AND password = '" + params.at(1) + "';");
    query.exec();
    bool res = (query.next()) ? true : false;

    db.close();

    return res;
}

QStringList SingletonMyDB::Statistics(QStringList params)
{
    db.open();
    QSqlQuery query(db);
    query.exec("use omagad;");

    query.prepare("SELECT login, task_number, variant, answer FROM USER WHERE "
                  "login = '" + params.at(0) + "';");
    query.exec();

    if(query.next())
    {
        auto ans = query.record();
        qDebug() << query.value(ans.indexOf("task_number")).toInt() << " # "
                 << query.value(ans.indexOf("variant")).toInt() << " # "
                 << query.value(ans.indexOf("answer")).toInt();
        db.close();

        QStringList temp;
        temp.push_back(query.value(ans.indexOf("task_number")).toString());
        temp.push_back(query.value(ans.indexOf("variant")).toString());
        temp.push_back(query.value(ans.indexOf("answer")).toString());
        return temp;
    } else {
        db.close();
        return QStringList{};
    }
}

bool SingletonMyDB::Check(QStringList params)
{
    db.open();
    QSqlQuery query(db);
    query.exec("use omagad;");

    query.prepare("SELECT answer FROM USER WHERE task_number = '" + params.at(0) + "' AND variant = '" + params.at(1) + "';");
    query.exec();

    if(!query.next())
        return false;

    auto rec = query.record();
    return query.value(rec.indexOf("answer")).toString() == params.at(2);
}
