#include <stdio.h>
#include "bankAPI.h"

extern invaild_input_str;
extern again_str;


int main()
{
	menu();
	int option = get_user_option();
	exec_option(option);
	return 1;
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