#include<stdio.h>
#include<stdlib.h>
#include "contacts.h"

int main(){

	char command;
	printf("Press \n q - quit \n l - list\n n - new contact \n r- remove contact");
	while((command = getCommand())!='q'){
		switch(command){
			case 'n':
				newContact();
				break;
			case 'l':
				listContacts();
				break;
			case 'r':
				removeContact();
				break;
			default:
				printf("Press \n q - quit \n l - list\n n - new contact \n ");
				break;
		}

	//printf ("******Bye********");
	}
	exit(0);
}
char getCommand(){

	char command;
	printf("\n Enter the Command: ");
	scanf("%c",&command);
	return tolower(command);
}
void newContact(){
	struct contact *contactInfo;
	
	contactInfo = malloc(sizeof(struct contact));
	printf("\n Please enter the details");
	printf("\n Name:");
	scanf("%s",contactInfo->name);
	printf("\n Number:");
	scanf("%s",contactInfo->phnumber);
	//printf("\n");
	if(head_contact == NULL){
		head_contact = contactInfo;
		tail_contact = contactInfo;
	}
	else{
		tail_contact ->next = contactInfo;
		tail_contact = contactInfo;
	}
	tail_contact ->next= NULL;
}

void listContacts(){
	struct contact *myContact;
	
	if(head_contact == NULL){
		printf("List Empty");
	}
	for(myContact = head_contact;myContact != NULL;myContact = myContact->next){
		printf("\t %s \t %s\n",myContact->name,myContact->phnumber);
	}

}


int sizeOfList(){
	struct contact *myContact;
	int count = 0;
	for(myContact = head_contact;myContact != NULL;myContact = myContact->next){
		++count;
	}
	return count;
}

void removeContact(){
	struct contact *myContact,*rmContact,*attachContact;
	int index = 0,choice = 129,i;
	
	for(myContact = head_contact;myContact != NULL;myContact = myContact->next){
		printf("%d . %s \n",++index,myContact->name);
		
	}
	printf("\n Enter contact to be removed: \n");
	scanf("%d",&choice);	
	if(choice < sizeOfList()){
		myContact = head_contact;
		for(i=1;i<choice-1;i++){
			myContact = myContact->next;		
		}
	
		rmContact = myContact->next;
		myContact->next = rmContact->next;
		

			
		
	}	
	else{
		printf("Not Found\n ");
	}	

						
}
