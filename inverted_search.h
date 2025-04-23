#ifndef INVERTED_SEARCH
#define INVERTED_SEARCH

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define     FILENAME_SIZE       50
#define     WORD_SIZE           25
#define     HASHTABLESIZE       28
#define     SUCCESS             1
#define     FAILURE             0
#define     DUPLICATE           -1

//structure for filelist
typedef struct node
{
    char filename[FILENAME_SIZE];
    struct node *file_link;
}Slist;

//structure for sub node
typedef struct sub_node
{
    int wordcount;
    char filename[FILENAME_SIZE];
    struct sub_node *sub_link;
}Sub_node;

//structure for main node
typedef struct main_node
{
    int filecount;
    char word[WORD_SIZE];
    Sub_node *sub_link;
    struct main_node *main_link;
}Main_node;

//structure for hashtable
typedef struct hashtable
{
    int index;
    Main_node *main_link;
}Hash_t;

/*read and validate arguments*/
int read_and_validate_args(char **argv, Slist **head);

/*after reading and validating add filename to filelist*/
int add_to_file_list(Slist **head, char *filename);

/*check filelist is empty*/
int check_list_empty(Slist *filelist);

/*create and initiallize hashtable*/
void create_hashtable(Hash_t *h_table);

/*store word in hashtable*/
void store_in_hashtable(int index, char *word, char *filename, Hash_t *h_table);

/*create database*/
void create_database(Slist *filelist, Hash_t *h_table);

/*display the database*/
void display_database(Hash_t *h_table);

/*serach word in database*/
void search_database(Hash_t *h_table);

/*save database in particular .txt file*/
void save_database(Hash_t *h_table);

/*update database using a particular .txt file*/
void update_database(Hash_t *h_table, Slist **filelist);

/*print file list*/
void print_list(Slist *head);

/*delete particular file from file list*/
void delete_file_from_list(Slist **filelist, char *filename);

/*check for file is empty or not*/
int is_file_empty(FILE *fp);

#endif