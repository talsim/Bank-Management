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
Userdata* print_and_scan_new_acc_messages();
void write_data_to_file(Userdata*);


