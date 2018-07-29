#define _CRT_NONSTDC_NO_DEPRECATE
#include "userdata.h"
#include "ioUtils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
#include <ctype.h>

static char* build_path(int);

#define ID_LEN 20
#define FILE_SIZE 150

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

Userdata* file2struct(int user_id)
{
	Userdata *ans = (Userdata*) malloc(sizeof(Userdata));
	char *path = build_path(user_id);
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
	free(path);
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

void show_file(int person_id)
{
	const char* show_file_format = "name: %s\nage: %d\nid: %d\nphone number: %d\naddress: %s\nmoney: %d\n";
	Userdata *user_data = NULL;
	char *path = build_path(person_id);
	FILE* userdata_file = fopen(path, "r");
	if (userdata_file != NULL)
	{
		user_data = file2struct(person_id);
		printf(show_file_format, user_data->name, user_data->age, user_data->id, user_data->phone_number, user_data->address, user_data->money);
	}
	else 
		printf("You entered wrong id!\n");
	free(user_data);
}

// build path for fopen location
char* build_path(int user_id)
{
	char *path = (char*)malloc(100*sizeof(char));
	strcpy(path, "..//BankUserData//");
	char file_name[ID_LEN] = "";
	itoa(user_id, file_name, 10);
	strcat(file_name, ".txt");
	strcat(path, file_name);
	return path;
}