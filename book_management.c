#include "book_management.h" 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




void choose_option1(Register *h, Book *last, Loans * head){
	char * title = (char *) malloc (sizeof(char) * 99);
	char * authors = (char *) malloc (sizeof(char) * 99);
//	char * year = (char *) malloc (sizeof(char) * 99);
	char * copies = (char *) malloc (sizeof(char) * 99);
	char * option = (char *) malloc (sizeof(char) * 99);
    char * _username = (char *) malloc (sizeof(char) * 99);
	char * _password = (char *) malloc (sizeof(char) * 99);
	char * year = (char *) malloc (sizeof(char) * 99);

    printf("Please choose an option:\n 1) Register an account\n 2) Login\n 3) Search for books\n 4) Dispaly all books\n 5) Quit\n Option:");	
//    getchar();
	scanf("%[^\n]%*c", option);
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
		scanf("%[^\n]%*c", _username);
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
        	choose_option1(h,last, head);
		}
		if(strcmp(option, "2") == 0)
        {
        	printf("Enter the authors of the book you wish to search:");
	        scanf("%[^\n]%*c", authors);
        	find_book_by_author (authors,last);
        	choose_option1(h,last, head);
		}
		if(strcmp(option, "3") == 0)
        {
        	printf("Enter the year of the book you wish to search:");
	         scanf("%[^\n]%*c", year);
	        if(atoi(year) == 0)
	    {
		printf("Please enter a valid year\n");
		choose_option1(last, h, head);
	    }
	        year = atoi(year);
		    find_book_by_year (year,last);
		    getchar(); 
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







int ordinary_user(Book *last, Register *h, char *username, Loans *head){
	char * title = (char *) malloc (sizeof(char) * 99);
	char * authors = (char *) malloc (sizeof(char) * 99);
	char * copies = (char *) malloc (sizeof(char) * 99);
	char * option = (char *) malloc (sizeof(char) * 99);
	char * year = (char *) malloc (sizeof(char) * 99);
	printf("Please choose an option:\n 1) Borrow a book\n 2) Return a book\n 3) Search for books\n 4) Dispaly all books\n 5) Log out\n Option:");
	scanf("%[^\n]%*c", option);
	if(strcmp(option, "1") == 1 && strcmp(option, "2") == 1 && strcmp(option, "3") == 1 && strcmp(option, "4") == 1 && strcmp(option, "5") == 1)
	{
		printf("Sorry, the option you entered was invalid, please try again.\n");
		do{
		    ordinary_user(last,h,username, head);
		    scanf("%[^\n]%*c", &option);
        }
		while(strcmp(option, "1") == 1 && strcmp(option, "2") == 1 && strcmp(option, "3") == 1 && strcmp(option, "4") == 1 && strcmp(option, "5") == 1);
	}
	if(strcmp(option, "1") == 0){
		
		last = borrow_book(last, head, username);
		getchar();
		ordinary_user(last,h,username, head);
		
	}
	if(strcmp(option, "2") == 0){
		
		last = return_book(last, head, username);
		getchar();
		ordinary_user(last,h,username, head);
	}
	
	
	
	if(strcmp(option, "3") == 0){
    	printf("Please choose an option:\n1)search books by title\n2)search books by author\n3)search books by year\n4)return to previous menu\nOption:");
	    scanf("%[^\n]%*c", option);
	    if(strcmp(option, "1") == 1 && strcmp(option, "2") == 1 && strcmp(option, "3") == 1 && strcmp(option, "4") == 1)
	    {
		    printf("Sorry, the option you entered was invalid, please try again.\n");
		    do{
		        ordinary_user(last,h,username, head);
		        scanf("%[^\n]%*c", &option);
            }
		    while(strcmp(option, "1") == 1 && strcmp(option, "2") == 1 && strcmp(option, "3") == 1 && strcmp(option, "4") == 1);
	
        }
        if(strcmp(option, "1") == 0)
        {
        	printf("Enter the title of the book you wish to search:");
	        scanf("%[^\n]%*c", title);
        	find_book_by_title (title,last);
        	printf("Logged in as : %s", username);
            ordinary_user(last,h,username, head);
		}
		if(strcmp(option, "2") == 0)
        {
        	printf("Enter the authors of the book you wish to search:");
	        scanf("%[^\n]%*c", authors);
        	find_book_by_author (authors,last);
        	printf("Logged in as : %s", username);
            ordinary_user(last,h,username, head);
		}
		if(strcmp(option, "3") == 0)
        {
        	printf("Enter the year of the book you wish to search:");
	        scanf("%[^\n]%*c", year);
	        if(atoi(year) == 0)
	    {
		printf("Please enter a valid year\n");
		ordinary_user(last,h,username, head);
	    }
		    find_book_by_year (year,last);
		    printf("Logged in as : %s", username);
            ordinary_user(last,h,username, head);
		    
	    }
	    if(strcmp(option, "4") == 0)
		{
		    ordinary_user(last,h,username, head);
	    } 
	    printf("Logged in as : %s", username);
        ordinary_user(last,h,username, head);
	
        } 
        if(strcmp(option, "4") == 0)
		{
			display_books(last);
			printf("Logged in as : %s\n", username);
            ordinary_user(last,h,username, head);
		  	
		}
		 if(strcmp(option, "5") == 0){
		 	choose_option1(h,last, head);
		 }
}




Book * borrow_book(Book *last, Loans *head, char *username){
//	printf("%s", last->title);
	int id;
	printf("Enter the ID number of the book you wish to borrow:");
	scanf("%d", &id);
	Book *p;
	int i=0;
	int count=0;
    p = last;
	for(i = 0; i<n+8; i++){
		if(p->id == id){
			if(strcmp(p->borrow, "y") == 0)
			{
				printf("Sorry, the book you want to borrow has been borrowed.\n");
				count += 1;
				return last;
			}
			else
			{
				p->borrow = "y";
				printf("You have successfully borrowed the book!\n");
				add_to_loans_list(head, username);
				store_books(last);
				count += 1;
				return last;
			}
		}
	
	p = p->Previous;
	}
	if(count == 0){
		printf("You have entered a wrong id.\n");
	}
//	getchar(); 
	return last;
}





Book * return_book(Book *last, Loans *head, char *username){
	int id;
	printf("Enter the ID number of the book you wish to return:");
	scanf("%d", &id);
	Book *p;
	int i=0;
	int count=0;
    p = last;
	for(i = 0; i<n+8; i++){
		if(p->id == id){
			if(strcmp(p->borrow, "y") == 0){
				p->borrow = "n";
				printf("You have successfully returned the book!\n");
				remove_from_loans_list(head, username);
				store_books(last);
				count += 1;
				return last;
				
			}
			if(strcmp(p->borrow, "n") == 0){
				printf("This book hasn't been borrowed.\n");
				count += 1;
				return last;
			}
			
	
		}
	p = p->Previous;
	}
	if(count == 0){
		printf("You have entered a wrong id.\n");
	}
//	getchar(); 
	return last;
	}

