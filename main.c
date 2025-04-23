/***********************
Gourav Singh
27 - 02 - 2025
Inverted Search Project
***********************/

#include "inverted_search.h"

char create_flag, update_flag;

int main(int argc, char *argv[])
{
	if(argc <= 1) //checking number of arguments
	{
		printf("ERROR: Insufficient number of arguments\n");
		return 0;
	}
	Slist *file_list_head = NULL;
	//reading and validating arguments as well as adding files into filelist
	read_and_validate_args(argv, &file_list_head); 
	//if file list empty terminate program
	if(check_list_empty(file_list_head) == SUCCESS) 
	{
		printf("INFO: No files to create a database\n");
		return 0;
	}
	print_list(file_list_head);
	//create hastable
	Hash_t h_table[HASHTABLESIZE];
	create_hashtable(h_table);
	int choice;
	
	do
	{
		printf("\n-----------------MENU-----------------\n");
		printf("1. Create Database\n2. Display Database\n3. Search Database\n4. Save Database\n5. Update Database\n6. Exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				if(!create_flag)
				{
					if(update_flag==1 &&  check_list_empty(file_list_head)==SUCCESS)  
						printf("INFO: No new files to create database\n");
					else 
						create_database(file_list_head, h_table);
					update_flag = create_flag = 1;
				}
				else
					printf("INFO: Database is already created\n\n");
				break;
			
			case 2:
				if(create_flag || update_flag)	
					display_database(h_table);
				else
					printf("INFO: Database not created\n\n");
				break;
				
			case 3:
				if(create_flag || update_flag)	
					search_database(h_table);
				else
					printf("INFO: Database not created\n\n");
				break;

			case 4:
				if(create_flag)	
					save_database(h_table);
				else
					printf("INFO: Database not created\n\n");
				break;
				
			case 5:
				if(!update_flag)
				{	
					update_database(h_table, &file_list_head);
					print_list(file_list_head);
				}
				else if(create_flag)
					printf("INFO: Update is not possible after create database\n");
				else
					printf("INFO: Database already updated\n\n");
				break;

			case 6:
				return SUCCESS;

			default:
			break;
		}
	} while (1);
	
	return 0;
}

