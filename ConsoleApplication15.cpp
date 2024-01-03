#include <iostream>
#include <cstring>
#include <fstream>
#include "TeleBook.h"
// another strange error: it says that strcpy is "may be unsafe". Didn't found any info about it
int main()
{
	TelephoneBook phonebook;

	phonebook.addCont("Yurii Yurii Yuriyovich", "+380661234545", "+380342212233", "+380663215454", "important info");
	phonebook.addCont("Oleg Oleg Olegovych", "+380664567878", "+380342223344");
	
	phonebook.searchCont("Oleg Oleg Olegovych");

	phonebook.showAllConts();

}
	
