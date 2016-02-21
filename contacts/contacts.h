
#define maxLength 128;

struct contact{
	char name [128];
	char phnumber [128];
	struct contact *next;
}mycontact,*head_contact,*tail_contact;

char getCommand();
void listContacts();
void newContact();
void removeContact();
