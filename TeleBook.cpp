#include <iostream>
#include <cstring>
#include <fstream>
#include "TeleBook.h"

void TelephoneBook::Contacts::setPIB(const char* pib)
{
   delete[] PIB;
   if (pib != nullptr)
   {
        PIB = new char[strlen(pib) + 1];
        strcpy(PIB, pib);
   }
   else
   {
       PIB = nullptr;
   }
}

void TelephoneBook::Contacts::setNumPers(const char* pers)
{
    if (pers != nullptr)
    {
        strcpy(numPers, pers);
    }
    else
    {
        numPers[0] = NULL;
    }
}

void TelephoneBook::Contacts::setNumHome(const char* home)
{
    if (home != nullptr)
    {
        strcpy(numHome, home);
    }
    else
    {
        numPers[0] = NULL;
    }
}

void TelephoneBook::Contacts::setNumWork(const char* work)
{
    if (work != nullptr)
    {
        strcpy(numWork, work);
    }
    else
    {
        numWork[0] = NULL;
    }
}

void TelephoneBook::Contacts::setInfo(const char* info_)
{
    delete[] info;
    if (info_ != nullptr)
    {
        PIB = new char[strlen(info_) + 1];
        strcpy(info, info_);
    }
}
