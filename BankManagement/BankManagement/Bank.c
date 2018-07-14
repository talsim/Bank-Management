#include <stdio.h>
void menu();
void menu();
void new_acc();
void edit();
void transact();
void see();
void erase();
void quit();
int get_user_option();
void exec_option(int);

// messages strings
static const char* new_acc_str = "Create new account";
static const char* edit_str = "Upadate information of existing account";
static const char* transact_str = "For trasactions";
static const char* see_str = "Check the details of an existing account";
static const char* erase_str = "Removing existing account";
static const char* quit_str = "Exit";
static const char* invaild_input_str = "Error: Invaild Input!";
static const char* again_str = "Try again";
static const char* welcome_str = "Welcome to the main menu";

int main()
{
	menu();
	int option = get_user_option();
	exec_option(option);
	return 1;
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

static int get_user_option()
{
	int user_ans = 0;
	scanf("%d", &user_ans);
	return user_ans;
}

static void exec_option(int option)
{
	switch (option)
	{
	case 1:
		new_acc();
		break;
	case 2:
		edit();
		break;
	case 3:
		transact();
		break;
	case 4:
		see();
		break;
	case 5:
		erase();
		break;
	case 6:
		quit();
		break;
	default:
		printf("%s%s\n", invaild_input_str, again_str);
		exec_option(get_user_option());
		break;
	}
}

void new_acc()
{
	printf("ACCOUNT IS MADE!\n");
}

void edit()
{

}

void transact()
{

}

void see()
{

}

void erase()
{

}

void quit()
{

}


