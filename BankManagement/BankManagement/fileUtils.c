#define _CRT_NONSTDC_NO_DEPRECATE
#include "userdata.h"
#include "ioUtils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
#include <ctype.h>

#define ID_LEN 20
#define FILE_SIZE 150

static char* build_path(int);
static Userdata* file2struct(char*);

int struct2file(Userdata *person)
{
	const char* write_format = "%s\n%d\n%d\n%d\n%s\n%d";
	char *path = build_path(person->id);
	FILE *userdata_file = fopen(path, "w+");
	if (userdata_file != NULL) 
	{
		fprintf(userdata_file, write_format, person->name, person->age, person->id, person->phone_number, person->address, person->money);
		fclose(userdata_file);
		printf("Have a great day sir!\n");
		return 1;
	}
	else 
	{
		printf("Error: cannot open file %d.txt!\n", person->id);
		return 0;
	}
	free(path);
	free(person);
}

static Userdata* file2struct(char *path) 
{
	Userdata *ans = (Userdata*) malloc(sizeof(Userdata));
	FILE *userdata_file = fopen(path, "r");
	if (userdata_file == NULL)
	{
		printf("Error: the id doesn't exist!\n");
		exit(0);
	}
	char buffer[100] = "";
	int line_num = 0;
	while (read_line(buffer, sizeof(buffer), userdata_file) != NULL) /* read a line */
	{
		switch (line_num)
		{
			case 0: 
				strcpy(ans->name, buffer);
				break;
			case 1:
				ans->age = atoi(buffer);
				break;
			case 2:
				ans->id = atoi(buffer);
				break;
			case 3:
				ans->phone_number = atoi(buffer);
				break;
			case 4:
				strcpy(ans->address, buffer);
				break;
			case 5:
				ans->money = atoi(buffer);
				break;
		}
		line_num++;
		strcpy(buffer, "");
	}
	return ans;
}

void remove_file(int person_id)
{
	char *path = build_path(person_id);
	int status = remove(path);
	if (status == 0)
		printf("The user with the id %d was successfuly removed!\n", person_id);
	else
		printf("Error: cannot remove the user %d\n", person_id);
}

void deposit_money(int user_id)
{
	int money_to_deposit = 0;
	printf("Please enter the amount of money to deposit: ");
	read_int(&money_to_deposit);
	char *path = build_path(user_id);
	Userdata *user_file = file2struct(path);
	user_file->money += money_to_deposit;
	int check = struct2file(user_file);
	if (check == 1)
		printf("The deposit was successful!\n");
	else
		printf("Error: the deposit counldn't go through!\n");
	free(user_file);
	free(path);
}

void withdraw_money(int user_id)
{
	int money_to_withdraw = 0;
	printf("Please enter the amount of money to withdraw: ");
	read_int(&money_to_withdraw);
	char *path = build_path(user_id);
	Userdata *user_file = file2struct(path);
	user_file->money -= money_to_withdraw;
	int check = struct2file(user_file);
	if (check == 1)
		printf("The withdraw was successful!\n");
	else
		printf("Error: the withdraw counldn't go through!\n");
	free(user_file);
	free(path);
}

void show_file(int person_id)
{
	const char* show_file_format = "name: %s\nage: %d\nid: %d\nphone number: %d\naddress: %s\nmoney: %d\n";
	Userdata *user_data = NULL;
	char *path = build_path(person_id);
	FILE* userdata_file = fopen(path, "r");
	if (userdata_file != NULL)
	{
		user_data = file2struct(path); 
		printf(show_file_format, user_data->name, user_data->age, user_data->id, user_data->phone_number, user_data->address, user_data->money);
	}
	else 
		printf("You entered wrong id!\n");
	free(user_data);
	free(path);
}

void edit_user_data(int user_id)
{
	char *path = build_path(user_id);
	Userdata *user_data = file2struct(path);
	show_file(user_id);
	printf("\n\n\n\n");
	printf("phone number: ");
	read_int(&user_data->phone_number);
	printf("address: ");
	read_line(user_data->address, strlen(user_data->address), stdin);
	struct2file(user_data);
	free(path);
	free(user_data);
}

// build path for fopen location
static char* build_path(int user_id)
{
	char *path = (char*)malloc(100*sizeof(char));
	strcpy(path, "..//BankUserData//");
	char file_name[ID_LEN] = "";
	itoa(user_id, file_name, 10);
	strcat(file_name, ".txt");
	strcat(path, file_name);
	return path;
}