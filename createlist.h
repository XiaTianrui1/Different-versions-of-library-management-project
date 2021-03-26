#ifndef CREATELIST__H 
#define CREATELIST__H


#include <stdio.h>



typedef struct _Book {
	    unsigned int id; //Book ID
		char *title; //book title
		char *authors; //comma separated list of authors
		unsigned int year; // year of publication
		unsigned int copies;
		char *borrow; //number of copies the library has
		struct _Book * Next;
		struct _Book * Previous;
}Book;

struct _loans{
    	char *username;
	int amount;
	struct _loans *Next;	
};
typedef struct _loans Loans;


struct _register{
	char *username;
	char *password;
	struct _register *Next;
};
typedef struct _register Register;



Register * create_register_list();
Register * Add_to_user_register(Register *h, char *_username, char *_password);
Book * create_book_list();
Book * load_books( char * file, Book *last); 
int store_users(Register *h);
