#ifndef MYDB_H
#define MYDB_H
//классическая реализация
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>

class SingletonMyDB;

/*!
 * \brief The SingletonDestroyerMyDB class
 *
 * Цели: \n
 * 1) Очищение памяти по завершении работы с классом SingletonMyDB
 */

class SingletonDestroyerMyDB
{
private:
    SingletonMyDB * p_instance;
public:
    /*!
     * \brief Деструктор SingletonDestroyerMyDB
     *
     * Очищает память, выделенную под SingletonMyDB
     */
    ~SingletonDestroyerMyDB() {delete p_instance;};
    /*!
     * \brief initialize
     * \param p
     *
     * Принимает указатель на класс SingletonMyDB и \n
     * сохраняет его.
     */
    void initialize(SingletonMyDB * p){p_instance = p;};
};

/*!
 * \brief The SingletonMyDB class
 *
 * Цели: \n
 * 1) Создание MySQL БД \n
 * 2) Обработка входящих запросов от TCP сервера к БД \n
 * 3) Возвращение ответа на TCP сервер
 */

class SingletonMyDB
{
private:
    static SingletonMyDB * p_instance;
    static SingletonDestroyerMyDB destroyer;
    QSqlDatabase db;
protected:
    SingletonMyDB() {};
    SingletonMyDB(const SingletonMyDB& );
    SingletonMyDB& operator = (SingletonMyDB &);
    ~SingletonMyDB() {};
    friend class SingletonDestroyerMyDB;

    /*!
     * \brief _init
     *
     * Инициализация подключения к MySQL серверу на основе DSN \n
     * Создание основной таблицы USER и двух базовых пользователей user и admin \n
    */
    void _init();
public:
    /*!
     * \brief getInstance
     * \return
     *
     * 1) Инициализирует класс SingletonMyDB, если он еще не был инициализирован \n
     * 2) Возвращает единственный экземпляр указателя на класс SingletonMyDB
     */
    static SingletonMyDB* getInstance(){
        if (!p_instance)
        {
            p_instance = new SingletonMyDB();
            destroyer.initialize(p_instance);
            p_instance->_init();
        }
        return p_instance;
    }

    /*!
     * \brief isReg
     *
     * Проверка существования в БД логина. \n
     * \param login Проверяемый логин
     * \return True или False, взависимости от успеха проверки.
     */
    bool isReg(QString login);
    /*!
     * \brief isMailAvailable
     *
     * Проверка существования в БД email. \n
     * \param email Проверяемый email
     * \return True или False, взависимости от успеха проверки.
     */
    bool isMailAvailable(QString email);
    /*!
     * \brief Register
     *
     * Создание запроса к БД, с целью добавления нового пользователя
     *
     * \param params . Список, который содержит основные данные нового пользователя: \n
     * 1) Логин \n
     * 2) Пароль \n
     * 3) Email
     *
     * \return True или False, в зависимости от успеха запроса.
     */
    bool Register(QStringList params);
    /*!
     * \brief Auth
     *
     * Создаёт запрос к БД, проверяющий существование пользователя с заданной информацией
     *
     * \param params Список, который содержит основные данные о пользователе: \n
     * 1) Логин \n
     * 2) Пароль \n
     * \return True или False, в зависимости от успеха запроса
     */
    bool Auth(QStringList params);
    /*!
     * \brief Statistics
     *
     * Создаёт запрос к БД, возвращающий статистику по заданному пользователю. \n
     * Статистика включает в себя следующее: \n
     * 1) Номер задачи \n
     * 2) Номер варианта \n
     * 3) Ответ на задачу \n
     *
     * \param params Список, содержащий логин пользователя
     *
     * \return Возвращает список, содержащий статистику.
     */
    QStringList Statistics(QStringList params);
    /*!
     * \brief Check
     *
     * Создает запрос к БД,проверяющий по списку, состоящему из: \n
     * 1) Номер задачи \n
     * 2) Номер варианта \n
     * 3) Ответ \n
     * правильность ответа
     *
     * \param params Список с параметрами, для проверки
     *
     * \return True или False, в зависимости от правильности введенных параметров для проверки.
     */
    bool Check(QStringList params);
};

#endif MYDB_H
