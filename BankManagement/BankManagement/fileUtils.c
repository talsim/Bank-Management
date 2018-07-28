#define _CRT_NONSTDC_NO_DEPRECATE
#include "userdata.h"
#include "ioUtils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
#include <ctype.h>

#define PATH_LEN 100
#define ID_LEN 20
#define FILE_SIZE 150
char path[PATH_LEN] = "..//BankUserData//";

static void build_path(int, char*);
static int extract_num_from_line(char*);
static void read_file_line(int, int, char*);

const char* write_format = "name: %s\nage: %d\nid: %d\nphone number: %d\naddress: %s\nmoney: %d";

void struct2file(Userdata *person)
{
	build_path(person->id, path);
	FILE* userdata_file = fopen(path, "w+");
	if (userdata_file != NULL) 
	{
		fprintf(userdata_file, write_format, person->name, person->age, person->id, person->phone_number, person->address, person->money);
		fclose(userdata_file);
		printf("The account was made succussfuly\n");
	}
	else
		printf("Error: cannot open file %d.txt!\n", person->id);
}

void remove_file(int person_id)
{
	build_path(person_id, path);
	int status = remove(path);
	if (status == 0)
		printf("The user with the id %d was successfuly removed!\n", person_id);
	else
		printf("Error: cannot remove the user %d\n", person_id);
}

void deposit_money(int user_id)
{
	int money_to_deposit;
	printf("Please enter the amount of money to deposit: ");
	read_int(&money_to_deposit);
	char money_line_str[100] = "";
	read_file_line(user_id, 5, money_line_str);
	int money_num = extract_num_from_line(money_line_str);
	//new function: struct_to_file();
}

void withdraw_money(int user_id)
{

}

void show_file(int person_id)
{
	char file_desc[FILE_SIZE] = "";
	build_path(person_id, path);
	FILE* userdata_file = fopen(path, "r");
	if (userdata_file != NULL)
	{
		fseek(userdata_file, 0, SEEK_SET);
		fread(file_desc, 1, FILE_SIZE, userdata_file);
		printf("%s\n", file_desc);
	}
	else 
		printf("You entered wrong id!\n");
}
// build path from int to string
static void build_path(int user_id, char *path)
{
	char file_name[ID_LEN] = "";
	itoa(user_id, file_name, 10);
	strcat(file_name, ".txt");
	strcat(path, file_name);
}

static int extract_num_from_line(char* money_val)
{
	while (*money_val)
	{
		if (isdigit(*money_val))
		{
			int num = atoi(money_val);
			return num;
		}
		else
			money_val++;
	}
}

static void read_file_line(int user_id, int lineNumber, char* money_line_str)
{
	build_path(user_id, path);
	FILE* userdata_file = fopen(path, "r+");
	int count = 0;
	if (userdata_file != NULL)
	{
		while (read_line(money_line_str, 100, userdata_file) != NULL) /* read a line */
		{
			if (count == lineNumber)
			{
				fclose(userdata_file);
				return; 
			}
			else
			{
				count++;
			}
		}
	}
	else
	{
		printf("Error: file does not exist!");
	}
}


