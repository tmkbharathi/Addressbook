#include "main.h"

int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		printf("\t########## ADDRESS BOOK #########\n");
		if(validate(argv[1])==SUCCESS)
		{
			printf("INFO : Validation done Successfully\n");
			if(addressmenu(argv[1])==SUCCESS)
			{
				printf("Thank You :)\n");
			}
			else
			{
				printf("INFO : Addressbook Program Failure\n");
			}
		}
		else
		{
			printf("INFO : Validation Failure\n");
			return FAILURE;
		}
	}
	else if(argc == 1)	
	{
		printf("USAGE: %s <addressbook.csv>\n", argv[0]);
		return FAILURE;
	}
	else
	{
		printf("INFO : Please Pass One <addressbook.csv> file\n");
		printf("USAGE: %s <addressbook.csv>\n", argv[0]);
		return FAILURE;
	}
}
