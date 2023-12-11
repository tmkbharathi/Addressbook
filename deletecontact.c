#include"main.h"

Status deletecontact(char * fname)
{
	contacts cont;
	FILE *fptr, *ftemp;
	if((fptr = fopen(fname, "r")) == NULL)
    {
		printf("ERROR: Invalid option\n");
		return FAILURE;
    }
    else
	{
		ftemp = fopen("temp.csv", "w");
		if(ftemp == NULL)
		{
			printf("ERROR: Invalid option\n");
			return FAILURE;
		}
	}

    char nameD[32];
    char phNoD[11];
    char emailIdD[32];

	printf("BY   :\n\t0. Back\n\t1. Name\n\t2. PhoneNo\n\t3. EmailId\nRESP : Enter your option: ");
    int option;
    scanf("%d", &option);

	int count = 0, keepCount = 0;
	switch(option)
	{
		case 0:
				return SUCCESS;
		case 1:
				printf("RESP : Enter the Name to delete contact : ");
				scanf("\n%[^\n]s", nameD);

				while(fread(&cont, sizeof(cont), 1, fptr) == 1)
				{
					if(strcmp(nameD, cont.name))
					{
						fwrite(&cont, sizeof(cont), 1, ftemp);
						count = 0;
					}
					else
					{
						count++;
						keepCount = count;
					}
				}
				break;
		case 2:
				printf("RESP : Enter the Phone number to delete contact : ");
				scanf("%s", phNoD);

				while(fread(&cont, sizeof(cont), 1, fptr) == 1)
				{
					if(strcmp(phNoD, cont.number))
					{
						fwrite(&cont, sizeof(cont), 1, ftemp);
						count = 0;
					}
					else
					{
						count++;
						keepCount = count;
					}
				}
				break;
		case 3:
				printf("RESP : Enter the Emailid to delete contact : ");
				scanf("%s", emailIdD);

				while(fread(&cont, sizeof(cont), 1, fptr) == 1)
				{
					if(strcmp(emailIdD, cont.emailid))
					{
						fwrite(&cont, sizeof(cont), 1, ftemp);
						count = 0;
					}
					
					else
					{
						count++;
						keepCount = count;
					}
				}
				break;
		default:
				printf("ERROR: Invalid option\n");
				return FAILURE;


	}

	
	fclose(fptr);
	fclose(ftemp);
    rename("temp.csv", fname);

	if(!keepCount)
	{
		printf("INFO : No Specified Contact Details Found\n");
		return NOTFOUND;
	}
	else
	{
		printf("INFO : Contact Details Deleted Successfully\n");
	}
	
	return SUCCESS;
	
}
