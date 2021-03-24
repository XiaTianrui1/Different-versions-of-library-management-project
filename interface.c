#define _CRT_SECURE_NO_DEPRECATE
#include "book_management.h" 
#include "varaible.h"  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>






void choose_option1(Register *h, Book *last, Loans * head){

	char * title = (char *) malloc (sizeof(char) * 99);
	char * authors = (char *) malloc (sizeof(char) * 99);
//	char * year = (char *) malloc (sizeof(char) * 99);
	char * copies = (char *) malloc (sizeof(char) * 99);
	
    char * _username = (char *) malloc (sizeof(char) * 99);
	char * _password = (char *) malloc (sizeof(char) * 99);
	unsigned int year; 
	char * option = (char *) malloc (sizeof(char) * 99); 

    printf("Please choose an option:\n 1) Register an account\n 2) Login\n 3) Search for books\n 4) Dispaly all books\n 5) Quit\n Option:");	
//    getchar();
	scanf("%[^\n]%*c", option);
//	printf("%s", option);
	if(strcmp(option, "1") == 1 && strcmp(option, "2") == 1 && strcmp(option, "3") == 1 && strcmp(option, "4") == 1 && strcmp(option, "5") == 1)
	{
		printf("Sorry, the option you entered was invalid, please try again.\n");
		do{
		    choose_option1(h,last, head);
		    scanf("%[^\n]%*c", &option);
        }
		while(strcmp(option, "1") == 1 && strcmp(option, "2") == 1 && strcmp(option, "3") == 1 && strcmp(option, "4") == 1 && strcmp(option, "5") == 1);
		
	}
	if(strcmp(option, "1") == 0)
	{
		printf("Please enter a username:");
//		getchar();
		scanf("%[^\n]%*c", _username);
		printf("Please enter a password:");
//		getchar();
		scanf("%[^\n]%*c", _password);
		if(search_username(_username,h) == 1)
		{
			printf("Sorry, registration unsuccessful, the username you entered already exists.\n");
		    choose_option1(h,last, head);
		        
		}
		printf("Registered library account successfully!\n");
		m +=1;
		h = Add_to_user_register(h, _username, _password);
		store_users(h);
		choose_option1(h,last, head);
		
	}
	if(strcmp(option, "2") == 0)
	{   
		printf("Please enter your username:");
//		getchar();
		scanf("%[^\n]%*c", _username);
//		printf("%s", _username);
		if(search_username(_username,h) == 0)
		{
			printf("Sorry, this username hasn't been registered.\n");
		    choose_option1(h,last, head);
		        
		}
		printf("Please enter your password:");
//		getchar();
		scanf("%[^\n]%*c", _password);
		if(check_password(_username, _password, h) == 1)
		{
			printf("Logged in as : %s\n", _username);
			if(strcmp(_username, "Librarian") == 0){
			    librarian_manage(last,h, head);
			    choose_option1(h,last, head);
					
			}
			else
			{
				ordinary_user(last,h,_username, head);
				choose_option1(h,last, head);
			}
		}
		else
		{
			printf("Incorrect password.\n");
			choose_option1(h,last, head);
		}
		
		
	}
	if(strcmp(option, "3") == 0)
	{
		printf("Please choose an option:\n1)search books by title\n2)search books by author\n3)search books by year\n4)return to previous menu\nOption:");
	    scanf("%[^\n]%*c", option);
	    if(strcmp(option, "1") == 1 && strcmp(option, "2") == 1 && strcmp(option, "3") == 1 && strcmp(option, "4") == 1)
	    {
		    printf("Sorry, the option you entered was invalid, please try again.\n");
		    do{
		        choose_option1(h,last, head);
		        scanf("%[^\n]%*c", &option);
            }
		    while(strcmp(option, "1") == 1 && strcmp(option, "2") == 1 && strcmp(option, "3") == 1 && strcmp(option, "4") == 1);
	
        }
        if(strcmp(option, "1") == 0)
        {
        	printf("Enter the title of the book you wish to search:");
	        scanf("%[^\n]%*c", title);
        	find_book_by_title (title,last);
        	//printf("Logged in as : %s", _username);
        	choose_option1(h,last, head);
		}
		if(strcmp(option, "2") == 0)
        {
        	printf("Enter the authors of the book you wish to search:");
	        scanf("%[^\n]%*c", authors);
        	find_book_by_author (authors,last);
        	//printf("Logged in as : %s", _username);
        	choose_option1(h,last, head);
		}
		if(strcmp(option, "3") == 0)
        {
        	printf("Enter the year of the book you wish to search:");
	        scanf("%d", &year);
//	        if(strspn(year,"0123456789")!=strlen(year))
//	        {
//	            printf("Sorry, you attemped to search an invalid book, please try again.");
//        	    choose_option1(h,last);
//		    }
		    find_book_by_year (year,last);
		    getchar(); 
//		    printf("Logged in as : %s", _username);
        	choose_option1(h,last, head);
		    
	    }
	    if(strcmp(option, "4") == 0)
		{
		    choose_option1(h,last, head);
	    } 
	    printf("Logged in as : %s", _username);
        choose_option1(h,last, head);
		
	}
	if(strcmp(option, "4") == 0)
	{
		display_books(last);
		choose_option1(h,last, head);
	}
	if(strcmp(option, "5") == 0)
	{
		exit;
	}
}





int search_username(char *_username, Register *h){
//	printf("%s", last->username);
    
	
		Register * p = (Register*)malloc(sizeof(Register));
	for(p = h; p!=NULL; p = p->Next){
		if(strcmp(p->username, _username) == 0)
//		{   printf("%s",h->Next->username);
//	        printf("%s",h->Next->password);
		{
				return 1;
			}
		}
	return 0;	
	}
	
	
	
	
int check_password(char *_username, char *_password, Register *h){
	Register *p;
//	printf("ai") ;
	for(p = h->Next; p!=NULL; p = p->Next){
		if(strcmp(p->username, _username) == 0)
	{ 
//            printf("%s",p->username);
//		    printf("%s",p->password);
			if(strcmp(p->password, _password) == 0)
			{    
			    return 1;	
			}
			else
			{
		    return 0;
		    }
		}
		
	}
	
}



void display_books(Book *last){
//	printf("%s", last->Previous->Previous->title);
//	   printf("%d", last->Previous->Previous->id);
//	   printf("%d", last->Previous->Previous->year);
//	   printf("%s", last->Previous->Previous->authors);
//	    printf("%d", last->Previous->Previous->copies);
	int count = 8+n;
//	printf("%d", count);
//    printf("%s", last->Previous->authors);
//    last = load_books( "book.txt", last);
	Book *p;
	printf("ID\tTitle\t\t\t\t\t\tAuthors\t\t\t\t\t\tYear\t\t\t\t\t\t\tCopies\n");
	for(p = last; count != 0; p = p->Previous){
		printf("%d\t%-40s\t%-40s\t%-50d\t%-4d\n", p->id, p->title, p->authors, p->year, p->copies);
		count--;
	}
		
	
}





int find_book_by_author (const char *author, Book *last){
	Book *p;
	int i=0;
	int count=0;
    p = last;
	for(i = 0; i<n+8; i++){
		if(strcmp(p->authors, author) == 0)
		{   
		    if(count == 0){
		        printf("ID\tTitle\t\t\t\t\t\tAuthors\t\t\t\t\t\tYear\t\t\t\t\t\t\tCopies\n");
			}
			printf("%d\t%-40s\t%-40s\t%-50d\t%-4d\n", p->id, p->title, p->authors, p->year, p->copies);
			count = count+1;
		}
		p = p->Previous;		
	}
	if(count==0)
	{
		printf("Sorry, couldn't find such books.\n");
	}
	return 0;
	
	
}





int find_book_by_title (const char *title, Book *last){
	Book *p;
	int i=0;
	int count=0;
    p = last;
	for(i = 0; i<n+8; i++){
		if(strcmp(p->title, title) == 0)
		{   
		    if(count == 0){
		        printf("ID\tTitle\t\t\t\t\t\tAuthors\t\t\t\t\t\tYear\t\t\t\t\t\t\tCopies\n");
			}
			printf("%d\t%-40s\t%-40s\t%-50d\t%-4d\n", p->id, p->title, p->authors, p->year, p->copies);
			count = count+1;
		}
		p = p->Previous;		
	}
	if(count==0)
	{
		printf("Sorry, couldn't find such books.\n");
	}
	return 0;
	
}





int find_book_by_year (unsigned int year, Book *last){
	Book *p;
	int i=0;
	int count=0;
    p = last;
	for(i = 0; i<n+8; i++){
		if(p->year == year)
		{   
		    if(count == 0){
		        printf("ID\tTitle\t\t\t\t\t\tAuthors\t\t\t\t\t\tYear\t\t\t\t\t\t\tCopies\n");	
			}
			printf("%d\t%-40s\t%-40s\t%-50d\t%-4d\n", p->id, p->title, p->authors, p->year, p->copies);
			count = count+1;
		}
		p = p->Previous;		
	}
	if(count==0)
	{
		printf("Sorry, couldn't find such books.\n");
	}
	return 0;
}
