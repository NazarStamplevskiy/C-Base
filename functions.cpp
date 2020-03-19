#include "functions.h"

#include <fstream>
#include <cctype>
#include <vector>
#include <iostream>

static const std::string dataBaseFilePath {"DB.txt"};
std::vector<Client> g_clients;

static double validateDouble(std::string number)
{
    if(number.empty())
    {
        return false;
    }

    int64_t dotsAmount = 0;
    for(size_t i = 0; i < number.size(); ++i)
    {
        if(!std::isdigit(number[i]))
        {
            if(number[i] == '.' || number[i] == ',')
            {
                if(!i || i == number.size() - 1)
                {
                    return false;
                }
                ++dotsAmount;
            }
            else
            {
                return false;
            }
        }
        else if(number[i] == '0' && i == 0 && i != number.size() - 1 && number[i + 1] != '.' && number[i + 1] != ',')
        {
            return false;
        }
        if(dotsAmount > 1)
        {
            return false;
        }
    }

    return true;
}

bool readFile()
{
    g_clients.clear();
    std::ifstream in{dataBaseFilePath};
    if(in.bad() || in.fail() || !in.is_open())
    {
        std::cout << "Missing file or bad input\n";
        return true; // file is missing. Will create one once updateFile is called
    }

    // Otherwise read from file
    while(!in.eof())
    {
        std::string number;
        std::string name;
        std::string surname;
        std::string money;

        in >> number;
        if(!in || in.fail())
        {
            std::cout << "Client number bad data\n";
            return false;
        }

        in >> name;
        if(!in || in.fail())
        {
            std::cout << "Client name bad data\n";
            return false;
        }

        in >> surname;
        if(!in || in.fail())
        {
            std::cout << "Client surname bad data\n";
            return false;
        }

        in >> money;
        if(!in || in.fail())
        {
            std::cout << "Client moneu bad data\n";
            return false;
        }

        if(!validateDouble(money))
        {
            std::cout << "Client money validation failed\n";
            return false;
        }

        double moneyParsed = std::atoi(money.c_str());

        g_clients.push_back(Client{name, surname, number, moneyParsed});
    }

    return true;
}

bool updateFile()
{
    std::ofstream out{dataBaseFilePath};

    for(auto it : g_clients)
    {
        out << it.getNumber() << " " << it.getName() << " " << it.getSurname() << " " << it.getMoneyAmount();
    }

    return true;
}