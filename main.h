#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact
{
	char name[32];
	char  number[11];
	char emailid[32];
}contacts;

typedef enum status
{
	FAILURE,
	SUCCESS,
	NOTFOUND,
}Status;

Status validate(char* fname);
Status addressmenu(char*fname);
Status addcontact(char* fname);
Status searchcontact(char* fname);
Status editcontact(char* fname);
Status deletecontact(char* fname);
Status listcontacts(char* fname);

