#define _CRT_SECURE_NO_DEPRECATE
#include "book_management.h" 
#include "varaible.h" 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>






int librarian_manage(Book *last, Register *h, Loans *head){
	
	char * title = (char *) malloc (sizeof(char) * 99);
	char * authors = (char *) malloc (sizeof(char) * 99);
//	char * year = (char *) malloc (sizeof(char) * 99);
	char * copies = (char *) malloc (sizeof(char) * 99);
	char * option = (char *) malloc (sizeof(char) * 99);
	unsigned int year;
	printf("Please choose an option:\n 1) Add a book\n 2) Remove a book\n 3) Search for books\n 4) Dispaly all books\n 5) Log out\n Option:");
//	getchar();
//    if(a!=0){
//    	getchar();
//	}
	scanf("%[^\n]%*c", option);
//	printf("%s", option);
	if(strcmp(option, "1") == 1 && strcmp(option, "2") == 1 && strcmp(option, "3") == 1 && strcmp(option, "4") == 1 && strcmp(option, "5") == 1)
	{
		printf("Sorry, the option you entered was invalid, please try again.\n");
		do{
		    librarian_manage(last,h, head);
		    scanf("%[^\n]%*c", &option);
        }
		while(strcmp(option, "1") == 1 && strcmp(option, "2") == 1 && strcmp(option, "3") == 1 && strcmp(option, "4") == 1 && strcmp(option, "5") == 1);
		
	}
	if(strcmp(option, "1") == 0){
		last = add_book(last);
		
		librarian_manage(last,h, head);
		
	}
	if(strcmp(option, "2") == 0){
	    last = remove_book(last, h, head);
	    
//	    getchar(); 
	    librarian_manage(last,h, head);
    }
    if(strcmp(option, "3") == 0){
    	printf("Please choose an option:\n1)search books by title\n2)search books by author\n3)search books by year\n4)return to previous menu\nOption:");
	    scanf("%[^\n]%*c", option);
	    if(strcmp(option, "1") == 1 && strcmp(option, "2") == 1 && strcmp(option, "3") == 1 && strcmp(option, "4") == 1)
	    {
		    printf("Sorry, the option you entered was invalid, please try again.\n");
		    do{
		        librarian_manage(last,h, head);
		        scanf("%[^\n]%*c", &option);
            }
		    while(strcmp(option, "1") == 1 && strcmp(option, "2") == 1 && strcmp(option, "3") == 1 && strcmp(option, "4") == 1);
	
        }
        if(strcmp(option, "1") == 0)
        {
        	printf("Enter the title of the book you wish to search:");
	        scanf("%[^\n]%*c", title);
        	find_book_by_title (title,last);
        	printf("Logged in as : Librarian\n");
        
        	librarian_manage(last,h, head);
		}
		if(strcmp(option, "2") == 0)
        {
        	printf("Enter the authors of the book you wish to search:");
	        scanf("%[^\n]%*c", authors);
        	find_book_by_author (authors,last);
        	printf("Logged in as : Librarian\n");
        	
//        	printf("%d", a);
        	librarian_manage(last,h, head);
		}
		if(strcmp(option, "3") == 0)
        {
        	printf("Enter the year of the book you wish to search:");
	        scanf("%d", &year);
//	        if(strspn(year,"0123456789")!=strlen(year))
//	        {
//	            printf("Sorry, you attemped to search an invalid book, please try again.");
//	            a += 1;
//        	    librarian_manage(last,h);
//		    }
		    find_book_by_year (year,last);
		    getchar(); 
		    printf("Logged in as : Librarian\n");
		    
		    librarian_manage(last,h, head);
		    
	    }
	    if(strcmp(option, "4") == 0)
		{
		
		    librarian_manage(last,h, head);
	    } 
	    printf("Logged in as : Librarian\n");
	   
	    librarian_manage(last,h, head);
	
        } 
        if(strcmp(option, "4") == 0)
		{
	
			display_books(last);
			printf("Logged in as : Librarian\n");
		
			librarian_manage(last,h, head);
		  	
		}
		if(strcmp(option, "5") == 0)
		{
		    choose_option1(h,last, head);
		}
 
}






Book * add_book(Book *last){
	
	int tmp;
	char * title = (char *) malloc (sizeof(char) * 99);
	char * authors = (char *) malloc (sizeof(char) * 99);
//	char * year = (char *) malloc (sizeof(char) * 99);
//	char * copies = (char *) malloc (sizeof(char) * 99);
	unsigned int year; // year of publication
	unsigned int copies;
	printf("Enter the title of the book you wish to add:");
	scanf("%[^\n]%*c", title);
	printf("Enter the authors of the book you wish to add:");
	scanf("%[^\n]%*c", authors);
	printf("Enter the year that the book you wish to add was released:");
	scanf("%d", &year);
	printf("Enter the number of copies of the book that you wish to add:");
	scanf("%d", &copies);
//	if(strspn(year,"0123456789")!=strlen(year) || strspn(copies,"0123456789")!=strlen(copies))
//	{
//	    printf("Sorry, you attemped to add an invalid book, please try again.");
//	    librarian_manage(last);
//	}
//	else
//	{
	   Book *p = (Book *)malloc(sizeof(Book));
	   p->title = title;
	   //printf("%s", p->title);
	   p->authors = authors;
	   p->year = year;
	   p->copies = copies;
	   p->id = n+8; 
	   p->borrow = "n";
	   last->Next = p;
	   p->Previous = last;
	   last = p;	   
	   printf("Book was successfully added!\n");
	   getchar();
	   n = n + 1;
//	   printf("%", last->title);
	   tmp = store_books(last);
//	   printf("%d",n);
	   return last;
//	}
	
	
}





Book * remove_book(Book *last, Register *h, Loans *head){
	char * title = (char *) malloc (sizeof(char) * 99);
	char * author = (char *) malloc (sizeof(char) * 99);
	unsigned int year;
	Book *t = (Book *)malloc(sizeof(Book));
	Book *pr;
	int i = 0;
	int a = 0;
	char * option = (char *) malloc (sizeof(char) * 99);
	printf("Please choose an option:\n1)remove books by title\n2)remove books by author\n3)remove books by year\n4)return to previous menu\nOption:");
	scanf("%[^\n]%*c", option);
	if(strcmp(option, "1") == 1 && strcmp(option, "2") == 1 && strcmp(option, "3") == 1 && strcmp(option, "4") == 1)
	{
		printf("Sorry, the option you entered was invalid, please try again.\n");
		do{
		    librarian_manage(last,h, head);
		    scanf("%[^\n]%*c", &option);
        }
		while(strcmp(option, "1") == 1 && strcmp(option, "2") == 1 && strcmp(option, "3") == 1 && strcmp(option, "4") == 1);
	
    }
    if(strcmp(option, "1") == 0)
    {    
        printf("Enter the title of the book you wish to move:");
	    scanf("%[^\n]%*c", title);
	    t = last;
//	    printf("%s", title);
	    for(i = 0; i<n+8; i++){
	    	
		    if(strcmp(t->title, title) == 0){
//			printf("%s", t->title);
			pr = t->Previous;
//			printf("%s", pr->title);
//			t = pr->Next;
			pr->Next = t->Next;
			t->Next->Previous = t->Previous;
			free((Book *)t); 
			a = a+1;
			t = t->Previous;
//			printf("%s", last->Previous->title);
		}
		else
		{
			t = t->Previous;
		}
	}
	if(a == 0)
	{
	    printf("Sorry, failed to search books.\n");	
	} 
	else 
	{
		printf("Remove books successfully!\n");
		return 0;
	}  	
	}
	if(strcmp(option, "2") == 0)
    {    
        printf("Enter the author of the book you wish to move:");
	    scanf("%[^\n]%*c", author);
	     t = last;
//	    printf("%s", title);
	    for(i = 0; i<n+8; i++){
	    	
		    if(strcmp(t->authors, author) == 0){
//			printf("%s", t->title);
			pr = t->Previous;
//			printf("%s", pr->title);
//			t = pr->Next;
			pr->Next = t->Next;
			t->Next->Previous = t->Previous;
			free((Book *)t); 
			
			a = a+1;
			t = t->Previous;
//			printf("%s", last->Previous->title);
		}
		else
		{
			t = t->Previous;
		}
    	
	}
	if(a == 0)
	{
	    printf("Sorry, failed to search books.\n");	
    	
	}
	else
	{
		printf("Remove books successfully!\n");
		return 0;
	}
}

	if(strcmp(option, "3") == 0)
    {    
        printf("Enter the year of the book you wish to move:");
	    scanf("%d", &year);
//	    printf("%d", year);
	    t = last;
//	    printf("%s", title);
	    for(i = 0; i<n+8; i++){
	    	
		    if(t->year == year){
//			printf("%s", t->title);
			pr = t->Previous;
//			printf("%s", pr->title);
//			t = pr->Next;
			pr->Next = t->Next;
			t->Next->Previous = t->Previous;
			free((Book *)t); 
			printf("Remove books successfully!\n");
			a = a+1;
			t = t->Previous;
			
//			printf("%s", last->Previous->title);
		}
		else
		{
			t = t->Previous;
		}
	}
	if(a == 0)
	{
	    printf("Sorry, failed to searchs books.\n");	
    	
	}
	else
	{
		getchar();
		return 0;
	}
}
	if(strcmp(option, "4") == 0){
		librarian_manage(last,h, head);
	}
	return last;

}

