#include "main.h"

Status editcontact(char * fname)
{
	contacts cont, edit;
	FILE *fp;
	if((fp = fopen(fname, "r+")) == NULL)
    {
		printf("ERROR: Unable to open\n");
		return FAILURE;
    }

    char nameE[32];
    char phNoE[11];
    char emailIdE[32];

	printf("BY   :\n\t0. Back\n\t1. Name\n\t2. PhoneNo\n\t3. Emailid\nRESP : Enter your option: ");
    int option;
    scanf("%d", &option);

	int count = 0;
	char res;
	switch(option)
	{
		case 0:
			    return SUCCESS;
		case 1:
				printf("RESP : Enter the Name which you want to edit: ");
				scanf("\n%[^\n]s", nameE);
				while(fread(&cont, sizeof(cont), 1, fp) == 1)
				{
					if(!strcmp(nameE, cont.name))
					{
						printf("FOUND: \nName    : %s\nPhone No: %s\nEmail Id: %s\n", cont.name, cont.number, cont.emailid);
						printf("RESP : Enter New Name: ");
						scanf("\n%[^\n]s", edit.name);
						
						printf("RESP : Are you want to edit phone no? y/n: ");
						scanf("\n%c", &res);
						if(res == 'y')
						{
							printf("RESP : Enter New Phone No: ");
							scanf("%s", edit.number);
						}
						else if(res == 'n')
						{
							printf("%s\n", cont.number);
							strcpy(edit.number, cont.number);
						}
						else
						{
							printf("ERROR: Invalid option\n");
						}

						printf("RESP : Are you want to edit emailid? y/n: ");
						scanf("\n%c", &res);
						if(res == 'y')
						{
							printf("RESP : Enter New Email Id: ");
							scanf("%s", edit.emailid);
						}
						else if(res == 'n')
						{
							printf("%s\n", cont.emailid);
							strcpy(edit.emailid,cont.emailid); 
						}
						else
						{
							printf("ERROR: Invalid option\n");
						}

						fseek(fp, -sizeof(cont), SEEK_CUR);
						fwrite(&edit, sizeof(cont), 1, fp);

						fclose(fp);
						count++;
						break;

					}
		
				}
				break;
		case 2:
				printf("RESP : Enter the Phone No which you want to edit: ");
				scanf("%s", phNoE);
				while(fread(&cont, sizeof(cont), 1, fp) == 1)
				{
					if(!strcmp(phNoE, cont.number))
					{
						printf("FOUND: \nName    : %s\nPhone No: %s\nEmail Id: %s\n", cont.name, cont.number, cont.emailid);
						printf("RESP : Enter New Phone No: ");
						scanf("%s", edit.number);
						
						printf("RESP : Are you want to edit name? y/n: ");
						scanf("\n%c", &res);
						if(res == 'y')
						{
							printf("RESP : Enter New Name: ");
							scanf("\n%[^\n]s", edit.name);
						}
						else if(res == 'n')
						{
							strcpy(edit.name,cont.name); 
						}
						else
						{
							printf("ERROR: Invalid option\n");
						}

						printf("RESP : Are you want to edit email? y/n: ");
						scanf("\n%c", &res);
						if(res == 'y')
						{
							printf("RESP : Enter New Email Id: ");
							scanf("%s", edit.emailid);
						}
						else if(res == 'n')
						{
							strcpy(edit.emailid,cont.emailid); 
						}
						else
						{
							printf("ERROR: Invalid option\n");
						}

						fseek(fp, -sizeof(cont), SEEK_CUR);
						fwrite(&edit, sizeof(cont), 1, fp);

						fclose(fp);
						count++;
						break;

					}
		
				}
				break;
		case 3:
				printf("RESP : Enter the Email Id which you want to edit: ");
				scanf("%s", emailIdE);
				while(fread(&cont, sizeof(cont), 1, fp) == 1)
				{
					if(!strcmp(emailIdE, cont.emailid))
					{
						printf("FOUND: \nName    : %s\nPhone No: %s\nEmail Id: %s\n", cont.name, cont.number, cont.emailid);
						printf("RESP : Enter New Email Id: ");
						scanf("%s", edit.emailid);
						
						printf("RESP : Are you want to edit Name? y/n: ");
						scanf("\n%c", &res);
						if(res == 'y')
						{
							printf("RESP : Enter New Name: ");
							scanf("\n%[^\n]s", edit.name);
						}
						else if(res == 'n')
						{
							strcpy(edit.name,cont.name); 
						}
						else
						{
							printf("ERROR: Invalid Option\n");
						}

						printf("RESP : Are you want to edit Phone No? y/n: ");
						scanf("\n%c", &res);
						if(res == 'y')
						{
							printf("RESP : Enter New Phone No: ");
							scanf("%s", edit.number);
						}
						else if(res == 'n')
						{
							strcpy(edit.number,cont.number); 
						}
						else
						{
							printf("ERROR: Invalid option\n");
						}

						fseek(fp, -sizeof(cont), SEEK_CUR);
						fwrite(&edit, sizeof(cont), 1, fp);

						fclose(fp);
						count++;
						break;
					
					}
		
				}
				break;
		default:
				printf("ERROR: Invalid option\n");
				return FAILURE;

	}
	if(count)
		return SUCCESS;
	else
		return NOTFOUND;
}

