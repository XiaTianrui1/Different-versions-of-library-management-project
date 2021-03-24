#ifndef INTERFACE__H 
#define INTERFACE__H


#include <stdio.h>



typedef struct _Book Book;
typedef struct _register Register;
typedef struct _loans Loans;


void choose_option1(Register *h, Book *last, Loans * head);
int search_username(char *_username, Register *h);
int check_password(char *_username, char *_password, Register *h);
int find_book_by_author (const char *author, Book *last);
int find_book_by_title (const char *title, Book *last);
int find_book_by_year (unsigned int year, Book *last);
void display_books(Book *last);
