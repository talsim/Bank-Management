#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bankAPI.h"
#include "userdata.h"
#include "fileUtils.h"
#include "ioUtils.h"

// menu messages
const char* new_acc_str = "Create new account";
const char* edit_str = "Upadate information of existing account";
const char* transact_str = "For trasactions";
const char* see_str = "Check the details of an existing account";
const char* erase_str = "Removing existing account";
const char* quit_str = "Exit";
const char* welcome_str = "Welcome to the main menu";

typedef int(*op)(int, int);

int plus(int x, int y) {
	return x + y;
}

int minus(int x, int y) {
	return x - y;
}

void menu()
{
	printf("\t\t\t\t\t%s\n\n\n\n", welcome_str);
	printf("1. %s\n", new_acc_str); // new_acc
	printf("2. %s\n", edit_str); // edit
	printf("3. %s\n", transact_str); // transact
	printf("4. %s\n", see_str); // see
	printf("5. %s\n", erase_str); // erase
	printf("6. %s\n", quit_str); // quit
}

void new_acc()
{
	Userdata *person = print_and_scan_new_acc_messages();
	struct2file(person);
}

void edit()
{
	int user_id;
	printf("Please enter the account's id: ");
	read_int(&user_id);
	edit_user_data(user_id);
}

void transact()
{
	int user_id;
	int ans;
	printf("Please enter the account's id: ");
	read_int(&user_id);
	printf("If you want to deposit money type 1, if you want to withdraw money type 0: ");
	read_int(&ans);
	if (ans == 1) deposit_money(user_id);
	else if (ans == 0) withdraw_money(user_id);
	else printf("Invaild input!\n");
}

void see()
{
	int user_id;
	printf("Please enter the account's id: ");
	read_int(&user_id);
	show_file(user_id);
}

void erase()
{
	int user_id;
	printf("Please enter your id: ");
	read_int(&user_id);
	remove_file(user_id);
}

static void edit_user_data(int user_id)
{
	Userdata *user_data = file2struct(user_id);
	show_file(user_id);
	printf("\n\n\n\n");
	printf("phone number: ");
	read_int(&user_data->phone_number);
	printf("address: ");
	read_line(user_data->address, strlen(user_data->address), stdin);
	struct2file(user_data);
	free(user_data);
}

static void withdraw_money(int user_id)
{
	choose_op(minus, user_id);

}

static void deposit_money(int user_id)
{
	choose_op(plus, user_id);
}

static void choose_op(op operation, int user_id) // operation is plus or minus
{
	int money_to_deposit = 0;
	printf("Please enter the amount of money to deposit: ");
	read_int(&money_to_deposit);
	Userdata *user_file = file2struct(user_id);
	user_file->money = operation(user_file->money, money_to_deposit);
	int check = struct2file(user_file);
	if (check == 1)
		printf("The deposit was successful!\n");
	else
		printf("Error: the deposit counldn't go through!\n");
	free(user_file);
}