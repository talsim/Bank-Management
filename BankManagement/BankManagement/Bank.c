#include <stdio.h>
//void menu();
//void new_acc();
//void edit();
//void transact();
//void see();
//void erase();
//void quit();

static const char* new_acc_str = "bla\n";

int main()
{
	printf("1. %s", new_acc_str); // new_acc

	//show_menu();
	//int option = get_user_option();
	//exec_option(option);
	//return 1;
}
//
//void menu()
//{
//	int ans;
//	printf("\t\t\t\t\tWelcome to the main menu\n\n\n");
//	printf("1. %s", new_acc_str); // new_acc
//	printf("2. Upadate information of existing account"); // edit
//	printf("3. For trasactions"); // transact
//	printf("4. Check the details of an existing account"); // see
//	printf("5. Removing existing account"); // erase
//	printf("6. Exit"); // quit
//	scanf("%d", &ans);
//	switch (ans)
//	{
//	case 1:
//		new_acc();
//		break;
//	case 2:
//		edit();
//		break;
//	case 3:
//		transact();
//		break;
//	case 4:
//		see();
//		break;
//	case 5: 
//		erase();
//	case 6: 
//		quit();
//	default:
//		printf("Error: Invaild Input!");
//	}
//}