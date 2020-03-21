#include "functions.h"

#include <fstream>
#include <cctype>
#include <vector>
#include <iostream>
using  std::string;
using std::cout;
using std::endl;

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
            if(in.eof())
            {
                return true;
            }
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
        out << it.getNumber() << " " << it.getName() << " " << it.getSurname() << " " << it.getMoneyAmount() << std::endl;
    }

    return true;
}

bool name_check(string str)
{
    
    if (str.empty())
    {
        cout << "Incorrect: empty string. ";
        return false;
    }
    if (str.size() >=32 )
    {
        cout << "Incorrect: lengt of your name is longer than 32! ";
        cout << str.length();
        return false;
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            cout << "Incorrect: Your number include spaces";
        }
        if (isdigit(str[i]))
        {
            cout << "Incorrect: Your name include numbers! ";
            return false;

        }
        if(iscntrl(str[i])||ispunct(str[i]))
        {
            cout << "Incorrect: Your name include graph:" << str[i]<<"  ";
            return false;
        }
        
    }
    return true;
}
bool number_check(string num)
{
    int pc = 0;
    if (num.empty())
    {
        cout << "Incorrect: empty string. " << endl;
        return false;
    }
    if (num.size() > 8||num.size()<8)
    {
        cout << "Incorrect: lengt of your number is not 8! " << endl;
        cout << num.length();
        return false;
    }
    

    for (int i = 0; i < num.size(); i++)
    {

        if (num[i] == ' ')
        {
            pc++;
        }
        if (!isdigit(num[i]))
        {
            cout << "Incorrect: Your number include letters! " << endl;
            return false;
            
        }
        if (iscntrl(num[i]) || ispunct(num[i]))
        {
            cout << "Incorrect: Your number include graph:" << num[i] << "  " << endl;
            return false;
            
        }
        if (pc >=1)
        {
            cout << "Your number has spaces! " << endl;
            return false;
            
        }
    }
    return true;
}

bool addNewClient(std::string name, std::string surname, std::string number, double money)
{
    for (int i = 0; i < g_clients.size(); i++)
    {
        if (g_clients[i].getNumber() == number)
        {
            cout << "This accout is already in database! " << endl;
            return false;
            break;
        }
    }
    g_clients.push_back(Client{ name,surname,number,money});
    return true;
}

bool removeClient(std::string number)
{
    for (auto it=g_clients.begin();it!=g_clients.end();++it)
    {
        if (it->getNumber() == number)
        {
            cout << "Ok deleting..." << endl;
            g_clients.erase(it);
            return true;
            break;
        }
        else
        {
            cout << "There is not account with this number: " << number << endl;
            return false;
            break;
        }
    }
    
    return true;
}
