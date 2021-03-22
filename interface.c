#include "book_management.h" 
 
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
		
	} //循环直到输入合法数值为止 
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
	
	
	
	
	
	
int search_username(char *_username, Register *h){
//	printf("%s", last->username);
    
	Register *p;
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
