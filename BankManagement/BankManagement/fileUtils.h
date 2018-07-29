#include "userdata.h"
#include <stdio.h>

int struct2file(Userdata*);
Userdata* file2struct(int);
void remove_file(int person_id);
void show_file(int);