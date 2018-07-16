void menu();
int get_user_option();
void exec_option(int);
void new_acc();
void edit();
void transact();
void see();
void erase();
void quit();
void print_and_scan_new_acc_messages();
void write_data_to_file();

typedef struct
{
	char name[20];
	int money;
	int id;
	int age;
	int phone_number;
	char address[20];
}user_data;