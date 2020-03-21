#include "Client.h"
#include <vector>
#include <iostream>
#include <string>

using std::cout;
using std::string;

std::vector<Client> g_clients;

Client::Client(std::string name, std::string surname, std::string number, double money)
    : m_name{ name }
    , m_surname{ surname }
    , m_money { money }
	, m_number { number }
{}


void Client::addMoney(double amount, std::string clientNumber)
{
	int k = std::stoi(clientNumber);    
	for (unsigned int i = 1; i <= g_clients.size(); i++) 
	{
		if (num[i] == k) 
		{
			m_money += amount;
			std::cout << "All money: " << m_money;
		}
	}
}

void Client::getMoney(double amount, std::string clientNumber)
{ 
	int k = std::stoi(clientNumber);
	for (unsigned int i = 1; i <= g_clients.size(); i++) 
	{
		if (num[i] == k) 
		{
			m_money -= amount;
			std::cout << "Taken money: " << m_money;
		}
	}
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




