#ifndef LIBRARIAN__H 
#define LIBRARIAN__H


#include <stdio.h>




typedef struct _Book Book;
typedef struct _register Register;
typedef struct _loans Loans; 

int librarian_manage(Book *last, Register *h, Loans *head);
Book * add_book(Book *last);
