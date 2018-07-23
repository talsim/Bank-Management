#include "ioUtils.h"
#include <string.h>
#include <stdlib.h>

// new_acc messages
const char* name_str = "Please enter your name: ";
const char* id_str = "Please enter your id: ";
const char* age_str = "Please enter your age: ";
const char* phone_number_str = "Please enter your phone number: ";
const char* address_str = "Please enter your address: ";
const char* money_str = "If you want to deposit money now, type 1, else type 0: ";
const char* amount_of_money_str = "Enter the amount of money to deposit: ";

// fgets without reading newline character
char *read_line(char *str, int n, FILE *stream)
{
	char *ans = fgets(str, n, stream);
	if (ans == NULL)
		return NULL;
	int newlineIndex = strcspn(str, "\n");
	str[newlineIndex] = 0;
	return str;
}


int read_int(int *num)
{
	scanf("%d", num);
	char c = getchar(); // remove newline from stdin
	return *num;
}

Userdata *print_and_scan_new_acc_messages()
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
	}
	return person;
}