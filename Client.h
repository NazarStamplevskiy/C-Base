#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <string>

class Client
{
public:
    explicit Client(std::string name, std::string surname, std::string number, double money);
    ~Client() = default;

    void        addMoney(double amount);
    void        getMoney(double amount);
    double      getMoneyAmount();
    std::string getName();
    std::string getSurname();
    std::string getNumber();

private:
    std::string m_name;
    std::string m_surname;
    std::string m_number;
    double      m_money;
};

#endif