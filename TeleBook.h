#pragma once
#include <iostream>
#include <cstring>
#include <fstream>

class TelephoneBook // phonebook itself
{
private: // here i put structure with info, constructors, destructor & setters
	struct Contacts 
	{
		char* PIB;
		char numHome[14] = {}; // for some reason it requires "= {}" to work. Dunno why
		char numPers[14] = {};
		char numWork[14] = {};
		char* info;
		Contacts() : PIB(nullptr), info(nullptr) // default constructor 
		{}
		Contacts(const char* pib, const char* pers, const char* home = "No home number.", const char* work = "No work number.", const char* info_ = "No information.") : PIB(nullptr), info(nullptr)
		{ // constructor with parameters
			setPIB(pib);
			setNumPers(pers);
			setNumHome(home);
			setNumWork(work);
			setInfo(info_);
		}
		~Contacts() // destructor
		{
			delete[] PIB;
			delete[] info;
		}

		void setPIB(const char* pib); // setters themselves are inline functions in TeleBook.cpp
		void setNumPers(const char* pers);
		void setNumHome(const char* home);
		void setNumWork(const char* work);
		void setInfo(const char* info_);

	};
	Contacts MaxConts[100]; // max amount of contacts
	int amount; // counting
public:
	void addCont(const char* pib, const char* pers, const char* home = "No home number.", const char* work = "No work number.", const char* info_ = "No information.")
	{ // adding contact
		if (amount < 100)
		{
			MaxConts[amount++] = Contacts(pib, pers, home, work, info_); // a bit easier way to add new contact
		}
		else
		{
			std::cout << "Phonebook is full.";
		}
	}
	void deleteCont(const char* pib)
	{ // deleting contact
		for (int i = 0; i < amount; i++)
		{
			if (std::strcmp(MaxConts[i].PIB, pib) == 0)
			{
				for (int j = i; j < amount - 1; j++)
				{
					MaxConts[j] = MaxConts[j + 1];
				}
				amount--;
			}
			else
			{
				std::cout << "Contact wasn't found";
			}
		}
	}
	Contacts* searchCont(const char* pib)
	{ // searching contact
		for (int i = 0; i < amount; i++)
		{
			if (strcmp(MaxConts[i].PIB, pib) == 0)
			{
				return &MaxConts[i];
			}
			else
			{
				std::cout << "Contact wasn't found.";
			}
		}
	}
	void showAllConts()
	{ // showing all contacts
		for (int i = 0; i <= amount; i++)
		{
			std::cout << "Lastname, Name and Surname: " << MaxConts[i].PIB << std::endl;
			std::cout << "Personal number: " << MaxConts[i].numPers << std::endl;
			std::cout << "Home number: " << MaxConts[i].numHome << std::endl;
			std::cout << "Work number: " << MaxConts[i].numWork << std::endl;
			std::cout << "Information: " << MaxConts[i].info << std::endl << std::endl;
		}
	}
	// I don`t know how to do saving and loading file. Maybe it was explained when i was at hospital
};
