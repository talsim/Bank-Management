#include <stdio.h>
#include "bankAPI.h"

// menu messages
const char* new_acc_str = "Create new account";
const char* edit_str = "Upadate information of existing account";
const char* transact_str = "For trasactions";
const char* see_str = "Check the details of an existing account";
const char* erase_str = "Removing existing account";
const char* quit_str = "Exit";
const char* welcome_str = "Welcome to the main menu";

// new_acc messages
const char* name_str = "Please enter your name: ";
const char* id_str = "Please enter your id: ";
const char* age_str = "Please enter your age: ";
const char* phone_number_str = "Please enter your phone number: ";
const char* address_str = "Please enter your address: ";
const char* money_str = "If you want to deposit money now, type 1, else type 0: ";
const char* amount_of_money_str = "Enter the amount of money to deposit: ";
const char* succses_str = "The money were deposited succesfuly!\n";
const char* goodbye_str = "Have a great day sir!\n";

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
{   // (!)change the absolute path(!)
	FILE *userdata_file = fopen("C:\\Users\\Tal_S\\Desktop\\Workspace\\Bank-Management\\BankManagement\\BankUserData\\account.txt", "a");
	if (userdata_file != NULL)
	{
		Userdata *p = print_and_scan_new_acc_messages();
		write_data_to_file(p);
	}
	else 
	{
		printf("Error: cannot open file!\n");
	}
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
	printf("");
}

static Userdata *print_and_scan_new_acc_messages()
{
	Userdata *person = (Userdata*) malloc(sizeof(Userdata));
	printf(name_str);
	scanf("%s", &person->name);
	printf(age_str);
	scanf("%d", &person->age);
	printf(id_str);
	scanf("%d", &person->id);
	printf(phone_number_str);
	scanf("%d", &person->phone_number);
	printf(address_str);
	scanf("%s", &person->address);
	printf(money_str);
	person->money = 0;
	int ans;
	scanf("%d", &ans);
	if (ans == 1)
	{
		printf(amount_of_money_str);
		scanf("%d", &person->money);
		printf(succses_str);
	}
	printf(goodbye_str);
	return person;
}

static void write_data_to_file(Userdata *p) //works
{
	printf("%s\n", p->name);
	//transfer data to file
} 