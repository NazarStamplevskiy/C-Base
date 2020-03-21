#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "Client.h"
#include <string>
#include <vector>

std::vector<Client> g_clients;

bool addMoney(double amount, std::string clientNumber);

bool getMoneyAmount(std::string clientNumber);

bool getMoney(std::string clientNumber);

void listClients();

#endif