#include "userdata.h"
#include <stdio.h>

const char* write_format = "name: %s\nage: %d\nid: %d\nphone number: %d\naddress: %s";

void write_data_to_file(Userdata *person)
{
	FILE *userdata_file = fopen("..//BankUserData//userID.txt", "a"); // change file name to the id
	if (userdata_file != NULL) {
		fprintf(userdata_file, write_format, person->name, person->age, person->id, person->phone_number, person->address);
		fclose(userdata_file);
	}
	else
		printf("Error: cannot open file!\n");

}