#include "userdata.h"
#include <stdio.h>
#include <string.h>

#define PATH_LEN 100
#define ID_LEN 20

static void build_path(int, char*);

const char* write_format = "name: %s\nage: %d\nid: %d\nphone number: %d\naddress: %s";

void write_data_to_file(Userdata *person)
{
	char path[PATH_LEN] = "..//BankUserData//";
	build_path(person->id, path);
	FILE *userdata_file = fopen(path, "a");
	if (userdata_file != NULL) {
		fprintf(userdata_file, write_format, person->name, person->age, person->id, person->phone_number, person->address);
		fclose(userdata_file);
	}
	else
		printf("Error: cannot open file!\n");
}

static void build_path(int user_id, char *path)
{
	char file_name[ID_LEN] = "";
	itoa(user_id, file_name, 10);
	strcat(file_name, ".txt");
	strcat(path, file_name);
}