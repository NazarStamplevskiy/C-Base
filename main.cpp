#include <iostream>
#include "Client.h"
#include "functions.h"
#include <string>

const int b8 = 256;

void print_comands() {
	std::cout << " Welcome to C-Base prog \n ";
	std::cout << " Enter num for command: \n ";
	std::cout << "1: Show clients list \n ";
	std::cout << "2: Add client \n ";
	std::cout << "3: Add money \n ";
	std::cout << "4: Delete client \n ";
	std::cout << "5: Show richest client \n ";
	std::cout << "6: Show Total bank money \n ";
}

bool check_cmd_by_num(char cmd[])
{	
	if (cmd[1] == static_cast<char>(0)) 
	{
		for (int i = 1; i <= 6; i++)
		{
			if (cmd[0] == i) {
				return true;
			}
			else
			{
				return false;
			}
		}
	}	
}

int check_cmd_by_word(char cmd[]) {
	for (int i = 0; cmd[i] != static_cast<char>(0); i++)
	{
		//DONE: if command entered fully
		if (cmd=="show clients list") 
		{
			return 1;
		}
		else if (cmd == "add client")
		{
			return 2;
		}
		else if (cmd == "add money")
		{
			return 3;
		}
		else if (cmd == "delete client")
		{
			return 4;
		}
		else if (cmd == "show richest client")
		{
			return 5;
		}
		else if (cmd == "show Total bank money")
		{
			return 6;
		}
		else 
		{
			return 0;//case of error
		}

	}
}

int main(int argc, char* argv[])
{
	bool flag_global=false;
	char cmd_word[b8];
	bool flag = true;
	int cmd_num;
	//readfile
	
	while (flag_global) 
	{
		while (flag)
		{
			print_comands();
			std::cin >> cmd_word;			//entering num or full of cmd
			if(check_cmd_by_num(cmd_word))	//if enterd num
			{
				cmd_num = std::atoi(cmd_word);
				flag = false;
			}
			else if (check_cmd_by_word(cmd_word))
			{
				// DONE: add checking via word
				cmd_num = check_cmd_by_word(cmd_word);
				flag = false;
			}
			else
			{
				std::cout << "error: incorect input\n";
			}
		}

		switch (cmd_num)
		{
		case 1:
		{
			listClients();
			break;
		}
		case 2://addin client
		{
			std::string name;
			std::string surname;
			std::string client_number;

			 flag = true;

			while (flag) 
			{
				std::cout << "enter name\n";
				std::cin >> name;
				if (name_check(name))
				{
					flag = false; 
				}
				else
				{
					std::cout << "incorect name\n";
				}

			}

			flag = true;

			while (flag)
			{
				std::cout << "enter surname\n";
				std::cin >> surname;
				if(name_check(surname))
				{
					flag = false;
				}
				else
				{
					std::cout << "incorrect surname\n";
				}
			}

			flag = true;

			while (flag)
			{
				std::cout << "enter number\n";
				std::cin >> client_number;
				if(number_check(client_number))
				{
					flag = false;
				}
				else
				{
					std::cout << "num has been taken\n";
				}
			}

			if (addNewClient(name, surname, client_number, 0)) 
			{
				addNewClient(name, surname, client_number, 0);
			}
			else 
			{
				std::cout << "unknown error occurred \n";

			};
			break;
		}
		case 3:	//adding babki
		{
			std::string client_number;
			char amount_word[b8];
			int amount;
			bool flag = true;
			while (flag) 
			{
				std::cout << "enter client number\n";
				std::cin >> client_number;
				if (number_check(client_number))
				{
					flag = false;
				}
				else
				{
					std::cout << "invalid number\n";
				}
			}

			flag = true;
			
			while (flag)
			{
				std::cout << "enter amount \n";
				std::cin >> amount;
				if (amount_check(amount_word)) 
				{
					amount = std::atoi(amount_word);
					flag = false;
				}
				else
				{
					std::cout << "incorect value\n";
				}


			}

			if (addMoney(client_num, amount)) 
			{
				addMoney(client_num, amount);
			}
			else
			{
				std::cout << "unknown error occured\n";
			};
			break;
			
		}

		case 4:
		{
			std::string client_number;
			flag = true;
			while (flag)
			{
				std::cout << "enter number of client\n";
				std::cin >> client_number;
				if(number_check(client_number))
				{
					flag = false;
				}
				else
				{
					std::cout << "incorect number\n";
				}

				if(removeClient(client_number))
				{
					removeClient(client_number);
				}
				else
				{
					std::cout << "unknown error occurred\n try again\n";
				}

			}
		}
		case 5:
		{
			std::cout << "Richest client:\n";
			std::cout<<getTheRichestClient()<<std::endl;
			// get richest client
		}

		case 6:
		{
			std::cout << "Total Bank money\n";
			std::cout << getTotalBankMoney()<<std::endl;
			//totalBankMoney
		}

		default:
			break;
		}

	}
    return 0;
}
