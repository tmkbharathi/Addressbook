#include"main.h"

Status validate(char* fname){
	printf("INFO : Validating ...\n");
	if(strchr(fname, '.')==NULL)
	{
		printf("INFO : Please Pass the file with .csv extension\n");
		return FAILURE;
	}
	else if(!strcmp(strchr(fname, '.'),".csv"))
	{
		FILE *exist=fopen(fname, "r");
	    if(exist==NULL)
		{
			printf("INFO : No addressbook in the name of %s\n", fname);
			printf("INFO : Addressbook name is set as %s\n", fname);
		}
	}
	else
	{
		printf("ERROR: Please Pass the file with .csv extension\n");
		return FAILURE;
	}
	printf("ERROR: Your Addressbook name is %s\n", fname);
	return SUCCESS;
}

Status addressmenu(char *fname){
	char option;
	do
	{
		printf("Menu :\n\t0. Exit\n\t1. Add Contact\n\t2. Search Contact\n\t3. Edit Contact\n\t4. Delete Contact\n\t5. List Contacts\n");
		printf("RESP : Enter your option: ");
		int option; char continu;
		scanf("%d", &option);
		switch(option)
		{
			case 0:
				return SUCCESS;
			case 1:
				if(addcontact(fname)==SUCCESS)
					printf("INFO : Contact Successfully added\n");
				else
					printf("ERROR: Contact not added due to some errors\n");
				break;
			case 2:
                if(searchcontact(fname)==FAILURE)
					 printf("ERROR: Searching not done due to some errors\n");
				break;
			case 3:
			   if(editcontact(fname)==SUCCESS)
					 printf("INFO : Editted Successfully\n");
               else
					 printf("INFO : Data Not Found\n");
				break;
			case 4:
				deletecontact(fname);
				break;
			case 5:
				if(listcontacts(fname)==FAILURE)
					printf("INFO : No Contact in Addressbook %s\n", fname);
				else
					printf("INFO : Listed Successfully\n");
				break;
			default:
				printf("INFO : Invalid Options\n");
				break;
		}
		printf("RESP : Do you want to continue? y/n: ");
		scanf("\n%c", &continu);
	} while(option != 'n');

	return SUCCESS;
}
