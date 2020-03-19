#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "Client.h"
#include <string>
#include <vector>

std::vector<Client> g_clients;

bool readFile();

bool updateFile();

bool addMoney(std::string clientNumber, double amount);

bool getMoneyAmount(std::string clientNumber);

bool getMoney(std::string clientNumber, double amount);

void listClients();

bool addNewClient(std::string name, std::string surname, std::string number, double money);

bool removeClient(std::string number);

#endif