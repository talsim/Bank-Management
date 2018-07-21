#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bankAPI.h"
#include "userdata.h"
#include "fileUtils.h"
#include "ioUtils.h"

// menu messages
const char* new_acc_str = "Create new account";
const char* edit_str = "Upadate information of existing account";
const char* transact_str = "For trasactions";
const char* see_str = "Check the details of an existing account";
const char* erase_str = "Removing existing account";
const char* quit_str = "Exit";
const char* welcome_str = "Welcome to the main menu";




void menu()
{
	printf("\t\t\t\t\t%s\n\n\n\n", welcome_str);
	printf("1. %s\n", new_acc_str); // new_acc
	printf("2. %s\n", edit_str); // edit
	printf("3. %s\n", transact_str); // transact
	printf("4. %s\n", see_str); // see
	printf("5. %s\n", erase_str); // erase
	printf("6. %s\n", quit_str); // quit
}

void new_acc() 
{
	Userdata *person = print_and_scan_new_acc_messages();
	write_data_to_file(person);
}

void edit()
{

}

void transact()
{

}

void see()
{

}

void erase()
{

}

void quit()
{
	
}
