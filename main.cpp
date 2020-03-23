#include <iostream>
#include "Client.h"
#include "functions.h"
#include <string>



void print_comands()
{
	std::cout << " Welcome to C-Base prog \n "
			  << " Enter num for command: \n "
			  << "1: Show clients list \n "
			  << "2: Add client \n "
			  << "3: Add money \n "
			  << "4: Delete client \n "
			  << "5: Show richest client \n "
			  << "6: Show Total bank money \n ";
}

bool check_cmd_by_num(std::string cmd)
{	
	int temp;
	if (cmd.length == 1) 
	{
		for (int i = 1; i <= 6; i++)
		{
			if (temp=std::atoi(cmd.c_str) == i)
			{
				return true;
			}
			
		}
	}
	return false;
}

int check_cmd_by_word(std::string cmd) 
{
	for (int i = 0; cmd[i] != static_cast<char>(0); i++)
	{
		//reDONE: if command entered fully
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
		else if (cmd == "show total bank money")
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
	std::string cmd_word;
	bool flag = true;
	int cmd_num;
	//readfile
	
	while (flag_global) 
	{
		while (flag)
		{
			print_comands();
														//entering num or full of cmd
			std::getline(std::cin, cmd_word);
			if(check_cmd_by_num(cmd_word))	//if enterd num
			{
				cmd_num = std::atoi(cmd_word.c_str);
				flag = false;
			}
			else if (check_cmd_by_word(cmd_word))
			{
				// reDONE: add checking via word
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
		case 1:																//showing list
		{
			listClients();
			break;
		}
		case 2:																//addin client
		{
			std::string name;
			std::string surname;
			std::string client_number;

			 flag = true;

			while (flag)													//entering name
			{
				std::cout << "enter name\n";
				std::getline(std::cin, name);
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

			while (flag)													//entering surname
			{
				std::cout << "enter surname\n";
				//std::cin >> surname;
				std::getline(std::cin, surname);
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

			while (flag)													//entering client number
			{
				std::cout << "enter number\n";
				//std::cin >> client_number;
				std::getline(std::cin, client_number);
				if(number_check(client_number))
				{
					flag = false;
				}
				else
				{
					std::cout << "num has been taken\n";
				}
			}

			bool retVal = addNewClient(name, surname, client_number, 0);			//verifying: adding new client

			if(!retVal)
			{
				std::cout << "Error occurred while adding new client \n";
			}
			break;
		}
		case 3:																			//adding babki
		{
			std::string client_number;
			std::string amount_word;
			int amount;
			bool flag = true;
			while (flag) 															//entering client number
			{
				std::cout << "enter client number\n";
				std::getline(std::cin, client_number);

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
			
			while (flag)															//entering amount
			{
				std::cout << "enter amount \n";
				std::getline(std::cin, amount_word);
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

			bool retVal = addMoney(client_number, amount);
																						//veryfying: adding money
			if(!retVal)
			{
				
				std::cout << "Error occured while adding money\n";

			}
			break;
			
		}

		case 4:
		{
			std::string client_number;
			flag = true;
			while (flag)														// entering client num
			{
				std::cout << "enter number of client\n";
				
				std::getline(std::cin,client_number);

				if(number_check(client_number))
				{
					flag = false;
				}
				else
				{
					std::cout << "incorect number\n";
				}

				bool retVal = removeClient(client_number);

				if(!retVal)
				{
					//removeClient(client_number);
					std::cout << "Error occurred while deleting client\n";
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
