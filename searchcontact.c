#include"main.h"

Status searchcontact(char * fname)
{
	contacts cont;
	FILE *fptr;
	if((fptr = fopen(fname, "r")) == NULL)
	{
		printf("ERROR: Unable to open the file\n");
		return FAILURE;
	}

	char names[32];
	char numbers[11];
	char emailids[32];

	printf("BY   :\n\t0. Back\n\t1. Name\n\t2. Phonenumber\n\t3. Emailid\nRESP : Enter your option: ");
	int option;
	scanf("%d", &option);

	int count = 0;
	switch(option)
	{
		case 0:
			return SUCCESS;
		case 1:
			printf("RESP : Enter a Name to search: ");
			scanf("\n%[^\n]s", names);
			while(fread(&cont, sizeof(cont), 1, fptr) == 1)
			{
				if(!strcmp(names, cont.name))
				{
					printf("FOUND: \nName    : %s\nPhone No: %s\nEmail Id: %s\n", cont.name, cont.number, cont.emailid);
					count++;
				}

			}
			if(!count)
			{
				printf("INFO : Contact not founded\n");
				return NOTFOUND;
			}
			else if(count > 1)
			{
				printf("INFO : Duplicate informations are presented\n");
			}
			break;
		case 2:
			printf("RESP : Enter a Phone No to search: ");
			scanf("%s", numbers);
			while(fread(&cont, sizeof(cont), 1, fptr) == 1)
			{
				if(!strcmp(numbers, cont.number))
				{
					printf("FOUND: \nName    : %s\nPhone No: %s\nEmail Id: %s\n", cont.name, cont.number, cont.emailid);
					count++;
				}

			}
			if(!count)
			{
				printf("INFO : Contact not founded\n");
				return NOTFOUND;
			}
			else if(count > 1)
			{
				printf("INFO : Duplicate informations are presented\n");
			}
			break;
		case 3:
			printf("RESP : Enter a Email Id to search: ");
			scanf("%s", emailids);
			while(fread(&cont, sizeof(cont), 1, fptr) == 1)
			{
				if(!strcmp(emailids, cont.emailid))
				{
					printf("FOUND: \nName    : %s\nPhone No: %s\nEmail Id: %s\n", cont.name, cont.number, cont.emailid);
					count++;
				}

			}
			if(!count)
			{
				printf("INFO : Contact not founded\n");
				return NOTFOUND;
			}
			else if(count > 1)
			{
				printf("INFO : Duplicate informations are presented\n");
			}
			break;
		default:
			printf("ERROR: Invalid option\n");	
	}

	return (fclose(fptr), SUCCESS);

}
