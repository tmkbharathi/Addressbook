#include "main.h"

Status listcontacts(char* fname)
{
	contacts cont;
	FILE *fptr;
	if((fptr = fopen(fname, "r")) == NULL)
    {
		printf("ERROR: Open file error\n");
	    return FAILURE;
     }

	int contactNos = 1;	
	printf("\n----------------------------------------\n");
	while(fread(&cont, sizeof(cont), 1, fptr) == 1)
	{
		printf("Contact (%d)\nName    : %s\nPhone No: %s\nEmail Id: %s\n----------------------------------------\n", contactNos, cont.name, cont.number, cont.emailid);
		contactNos++;
	}
	if(1 == contactNos)
	{
		return FAILURE;
	}
	
	fclose(fptr);
	return SUCCESS;

}
