#define _CRT_NONSTDC_NO_DEPRECATE
#include "userdata.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  

#define PATH_LEN 100
#define ID_LEN 20
#define FILE_SIZE 100
char path[PATH_LEN] = "..//BankUserData//";


static void build_path(int, char*);

const char* write_format = "name: %s\nage: %d\nid: %d\nphone number: %d\naddress: %s";

void write_data_to_file(Userdata *person)
{
	build_path(person->id, path);
	FILE* userdata_file = fopen(path, "a");
	if (userdata_file != NULL) {
		fprintf(userdata_file, write_format, person->name, person->age, person->id, person->phone_number, person->address);
		fclose(userdata_file);
		printf("The account was made succussfuly!\n");
	}
	else
		printf("Error: cannot open file!\n");
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

void show_file(int person_id)
{
	char file_desc[FILE_SIZE] = "";
	build_path(person_id, path);
	FILE* userdata_file = fopen(path, "r");
	if (userdata_file != NULL)
	{
		fseek(userdata_file, 0, SEEK_SET);
		fread(file_desc, 1, sizeof(Userdata) + 35, userdata_file);
		printf("%s\n", file_desc);
	}
	else printf("You entered wrong id!\n");
}
// build path from int to string
static void build_path(int user_id, char *path)
{
	char* loc_path = path;
	char file_name[ID_LEN] = "";
	itoa(user_id, file_name, 10);
	strcat(file_name, ".txt");
	strcat(path, file_name);
}