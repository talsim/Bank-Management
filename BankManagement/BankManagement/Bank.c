#include <stdio.h>
#include "bankAPI.h"
#include "ioUtils.h"

int get_user_option();
void exec_option(int);

// menu messages
const char* invaild_input_str = "Error: Invaild Input!";
const char* again_str = "Try again";


int main()
{	
	menu();
	int option = get_user_option();
	exec_option(option);
 	return 0;

}					

static int get_user_option()
{
	int user_ans = 0;
	read_int(&user_ans);
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
		exit(0);
		break;
	default:
		printf("%s\n%s\n", invaild_input_str, again_str);
		exec_option(get_user_option());
		break;
	}
}



