#include "Client.h"

Client::Client(std::string name, std::string surname, std::string number, double money)
    : m_name{ name }
    , m_surname{ surname }
    , m_number { number }
    , m_money { money }
{}

void Client::addMoney(double amount)
{
    m_money += amount;
}

void Client::getMoney(double amount)
{
    m_money -= amount;
}

double Client::getMoneyAmount()
{
    return m_money;
}

std::string Client::getName()
{
    return m_name;
}

std::string Client::getSurname()
{
    return m_surname;
}

std::string Client::getNumber()
{
    return m_number;
}