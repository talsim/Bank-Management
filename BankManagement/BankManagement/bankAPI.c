#include <stdio.h>
#include "bankAPI.h"
FILE *userdata_file;
Userdata* print_and_scan_new_acc_messages();
void write_data_to_file(Userdata*);

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
const char* write_format = "name: %s\nage: %d\nid: %d\nphone number: %d\naddress: %s";


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

void new_acc() // needs to get the person data
{
	userdata_file = fopen("..//BankUserData//userID.txt", "a");
	if (userdata_file != NULL)
	{
		Userdata *person = print_and_scan_new_acc_messages();
		write_data_to_file(person);
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
	
}

static Userdata *print_and_scan_new_acc_messages()
{
	Userdata *person = (Userdata*)malloc(sizeof(Userdata));
	printf(name_str);
	read_line(person->name, strlen(person->name), stdin);
	printf(age_str);
	read_int(&person->age);
	printf(id_str);
	read_int(&person->id);
	printf(phone_number_str);
	read_int(&person->phone_number);
	printf(address_str);
	read_line(person->address, strlen(person->address), stdin);
	printf(money_str);
	person->money = 0;
	int ans;
	read_int(&ans);
	if (ans == 1)
	{
		printf(amount_of_money_str);
		read_int(&person->money);
		printf(succses_str);
	}
	printf(goodbye_str);
	return person;
}

static void write_data_to_file(Userdata *person)
{
	fprintf(userdata_file, write_format, person->name, person->age, person->id, person->phone_number, person->address);
	fclose(userdata_file);
}

// fgets without reading newline character
static char *read_line(char *str, int n, FILE *stream)
{
	char *ans = fgets(str, n, stream);
	if (ans == NULL)
		return NULL;
	int newlineIndex = strcspn(str, "\n");
	str[newlineIndex] = 0;
	return str;
}


static int read_int(int *num)
{
	scanf("%d", num);
	char c = getchar(); // remove newline from stdin
	return *num;
}