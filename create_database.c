#include "inverted_search.h"

char word[WORD_SIZE];

void create_database(Slist *filelist, Hash_t *h_table)
{
	
	printf("-------------------------CREATING DATABASE-------------------------\n");
	char ch, index;
	//loop for files
	while (filelist)
	{
		// printf("%s\n", filelist->filename);
		FILE *fptr = fopen(filelist->filename, "r");
		if(fptr==NULL)
		{
			printf("unable to open %s\n", filelist->filename);
		}

		//loop for a particular file
		while ((ch=fgetc(fptr))!=EOF)
		{
			int i=0;
			if(ch==' ' || ch=='\n')
				continue;

			//loop for each word inside a file
			while (!(ch==' ' || ch=='\n' || ch==EOF))  //a word can end either with space or new line
			{
				word[i++] = ch;
				ch = fgetc(fptr);
			}
			word[i] = '\0';
			// printf("word = %s\n", word);

			if(word[0]>='a' && word[0]<='z')  //lowercase
			{
				index = word[0] - 'a';
			}
			else if(word[0]>='A' && word[0]<='Z')  //uppercase
			{
				index = word[0] - 'A';
			}
			else if(isdigit(word[0])) //digits
			{
				index = 26;
			}
			else //special characters
			{
				index = 27;
			}
			// printf("index = %d\n", index);
			//store word in hashtable
			store_in_hashtable(index, word, filelist->filename, h_table); 

		}
		printf("INFO: %s done\n", filelist->filename);
		fclose(fptr);
		filelist = filelist->file_link;
	}
	printf("-------------------------DATABASE CREATED--------------------------\n");	
}

void store_in_hashtable(int index, char *word, char *filename, Hash_t *h_table)
{
	if(h_table[index].main_link==NULL)
	{
		Main_node *new_main_node = (Main_node*)malloc(sizeof(Main_node));
		new_main_node->filecount = 1;
		strcpy(new_main_node->word, word);
		new_main_node->main_link = NULL;
		new_main_node->sub_link = NULL;
		
		Sub_node *new_sub_node = (Sub_node*)malloc(sizeof(Sub_node));
		strcpy(new_sub_node->filename, filename);
		new_sub_node->wordcount = 1;
		new_sub_node->sub_link = NULL;

		new_main_node->sub_link = new_sub_node;

		h_table[index].main_link = new_main_node;

		return ;
	}

	Main_node *temp_main = h_table[index].main_link, *prev_main = NULL;
	while (temp_main)
	{
		if(!strcmp(temp_main->word, word))
		{
			Sub_node *temp_sub = temp_main->sub_link, *prev_sub = NULL;
			while (temp_sub)
			{
				if(!strcmp(temp_sub->filename, filename))
				{
					temp_sub->wordcount++;
					return ;
				}
				prev_sub = temp_sub;
				temp_sub = temp_sub->sub_link;
			}
			Sub_node *new_sub_node = (Sub_node*)malloc(sizeof(Sub_node));
			strcpy(new_sub_node->filename, filename);
			new_sub_node->wordcount = 1;
			new_sub_node->sub_link = NULL;

			prev_sub->sub_link = new_sub_node;
			temp_main->filecount++;


			return ;
		}
		prev_main = temp_main;
		temp_main = temp_main->main_link;
	}
	Main_node *new_main_node = (Main_node*)malloc(sizeof(Main_node));
	new_main_node->filecount = 1;
	strcpy(new_main_node->word, word);
	new_main_node->main_link = NULL;
	new_main_node->sub_link = NULL;
	
	Sub_node *new_sub_node = (Sub_node*)malloc(sizeof(Sub_node));
	strcpy(new_sub_node->filename, filename);
	new_sub_node->wordcount = 1;
	new_sub_node->sub_link = NULL;

	new_main_node->sub_link = new_sub_node;

	prev_main->main_link = new_main_node;

	return ;
}
