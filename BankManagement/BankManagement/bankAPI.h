typedef struct
{
	char name[20];
	int money;
	int id;
	int age;
	int phone_number;
	char address[20];
} Userdata;

void menu();
int get_user_option();
void exec_option(int);
void new_acc();
void edit();
void transact();
void see();
void erase();
void quit();
char *read_line(char *str, int n, FILE *stream);
int read_int(int *num);