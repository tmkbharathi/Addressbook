#include"main.h"

Status addcontact(char * fname)
{
	contacts cont;
	FILE *fptr;
	if((fptr = fopen(fname, "a")) == NULL)
	{
		printf("ERROR: Unable to open the file\n");
		return FAILURE;
	}
	int i, checknumber = 0, checkemail = 0;

	printf("RESP : Enter the Name : ");
	scanf("\n%[^\n]s", cont.name);
	printf("RESP : Enter the Phone number : ");
	scanf("%s", cont.number);
	printf("RESP : Enter the Email Id: ");
	scanf("%s", cont.emailid);

	for(i= 0; i < strlen(cont.number); i++)
	{
		if(strlen(cont.number) != 10)
		{
			printf("ERROR: Please pass the 10 digit number\n");
			return FAILURE;
		}
		else if((cont.number[i] > '0') && (cont.number[i] < '9'))
		{
			checknumber = 1;
		}
	}
	if(checknumber == 0)
	{
		printf("ERROR: Please pass the numbers only\n");
	}
	for(i = 0; i < strlen(cont.emailid); i++)
	{
		if((cont.emailid[i] == '@') || (cont.emailid[i] == '.'))
		{
			checkemail++;
		}
	}
	if(checkemail < 2)
	{
			printf("ERROR: Please pass correct Emailid, eg: xyz@gmail.com\n");
			return FAILURE;
	}

	int success = fwrite(&cont, sizeof(cont), 1, fptr);
	if(!success)
	{
		return FAILURE;
	}

	return (fclose(fptr),SUCCESS);
}
