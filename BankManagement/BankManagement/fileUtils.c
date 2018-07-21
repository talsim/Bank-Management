#include "userdata.h"
#include <stdio.h>
#include <string.h>

#define PATH_LEN 100
#define ID_LEN 20
const char path[PATH_LEN] = "..//BankUserData//";

static void build_path(int, char*);

const char* write_format = "name: %s\nage: %d\nid: %d\nphone number: %d\naddress: %s";

void write_data_to_file(Userdata *person)
{
	build_path(person->id, path);
	FILE *userdata_file = fopen(path, "a");
	if (userdata_file != NULL) {
		fprintf(userdata_file, write_format, person->name, person->age, person->id, person->phone_number, person->address);
		fclose(userdata_file);
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

static void build_path(int user_id, char *path)
{
	char file_name[ID_LEN] = "";
	itoa(user_id, file_name, 10);
	strcat(file_name, ".txt");
	strcat(path, file_name);
}