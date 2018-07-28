#include "userdata.h"
#include <stdio.h>

void struct2file(Userdata*);
Userdata* file2struct(char*);
void remove_file(int person_id);
void show_file(int);
void deposit_money(int);
void withdraw_money(int); 