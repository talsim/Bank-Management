#include <stdio.h>
#include "bankAPI.h"

// menu messages
const char* invaild_input_str = "Error: Invaild Input!";
const char* again_str = "Try again";

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

int main()
{
	menu();
	int option = get_user_option();
	exec_option(option);
	return 1;
}					

int get_user_option()
{
	int user_ans = 0;
	scanf("%d", &user_ans);
	return user_ans;
}

void exec_option(int option)
{
	switch (option)
	{
	case 1:
		new_acc();
		break;
	case 2:
		edit();
		break;
	case 3:
		transact();
		break;
	case 4:
		see();
		break;
	case 5:
		erase();
		break;
	case 6:
		quit();
		break;
	default:
		printf("%s\n%s\n", invaild_input_str, again_str);
		exec_option(get_user_option());
		break;
	}
}

void print_and_scan_new_acc_messages()
{
	user_data person;
	printf(name_str);
	scanf("%s", &person.name);
	printf(age_str);
	scanf("%d", &person.age);
	printf(id_str);
	scanf("%d", &person.id);
	printf(phone_number_str);
	scanf("%d", &person.phone_number);
	printf(address_str);
	scanf("%s", &person.address);
	printf(money_str);
	int ans;
	scanf("%d", &ans);
	if (ans == 1)
	{
		person.money = 0;
		printf(amount_of_money_str);
		scanf("%d", &person.money);
		printf(succses_str);
	}
	else printf(goodbye_str);
}

void write_data_to_file() // need to get the data from print_and_scan_new_acc_messages
{
	printf("");
}

