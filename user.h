#ifndef USER__H 
#define USER__H


#include <stdio.h>


typedef struct _Book Book;
typedef struct _register Register;
typedef struct _loans Loans; 

int ordinary_user(Book *last, Register *h, char *username, Loans *head);
Book * borrow_book(Book *last, Loans *head, char *username);
Book * return_book(Book *last, Loans *head, char *username);
