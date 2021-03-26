#define _CRT_SECURE_NO_DEPRECATE
#include "book_management.h" 
#include "varaible.h"  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



Book * create_book_list(){
		Book *h = (Book *)malloc(sizeof(Book));
		Book *last = (Book *)malloc(sizeof(Book));
		last = h;
		last = load_books("book.txt", last);
		return last; 
		}
		
		

Book * load_books( char *file, Book *last){
	int i = 0;
	FILE *fp = fopen(file, "r");
	if(fp == NULL){
		printf("Can not open the file"); 
	    } 
	else
	{
	    for(i = 0; i<8+n; i++){
	        Book *tmp = (Book *)malloc(sizeof(Book));
	        tmp->title= (char *) malloc (sizeof(char) * 99);
	        tmp->authors= (char *) malloc (sizeof(char) * 99);
	        tmp->borrow= (char *) malloc (sizeof(char) * 99);
			fscanf(fp, "%d\t%[^\t]%*c\t%[^\t]%*c\t%d\t%d\t%[^\n]%*c\n", &tmp->id, tmp->title, tmp->authors, &tmp->year, &tmp->copies, tmp->borrow);
			last->Next = tmp;
			tmp->Previous = last;
			last = tmp;
            }
            fclose(fp);
//            	printf("%s", last->Previous->title);
//	   printf("%d", last->Previous->Previous->Next->id);
//	   printf("%d", last->Previous->Previous->Next->year);
//	   printf("%s", last->Previous->Previous->Next->authors);
//	    printf("%d", last->Previous->Previous->Next->copies);
            return last;
}
}



Register * create_register_list(){
	int i = 0;
//	Register *p = (Register *)malloc(sizeof(Register));
	Register *h = (Register *)malloc(sizeof(Register));
//	p->username= (char *) malloc (sizeof(char) * 99);
//	p->password= (char *) malloc (sizeof(char) * 99);
	h->Next = NULL;
	FILE *fp = fopen("users.txt", "r");
	if(fp == NULL){
		printf("Can not open the file"); 
	    } 
	else{
		for(i = 0; i<5+m; i++){
			Register *p = (Register *)malloc(sizeof(Register));
			p->username= (char *) malloc (sizeof(char) * 99);
	        p->password= (char *) malloc (sizeof(char) * 99);
			fscanf(fp, "%[^\t]%*c\t%[^\n]%*c\n", p->username,p->password);
			p->Next = h->Next;
			h->Next = p;
			
		    
		}
//		printf("%s", h->Next->Next->password);
		fclose(fp);
		return h;
	}

	
}





Register *Add_to_user_register(Register *h, char *_username, char *_password){
//	Register *p;
    Register *p = (Register *)malloc(sizeof(Register));
	p->username = _username;
	p->password = _password;
    p->Next = h->Next;
    h->Next = p;
	return h;
//	printf("hh");
		
}



int store_users(Register *h){
	Register *p = h->Next;
	int i = 0;
	FILE *file = fopen("users.txt", "w");
	fprintf(file, "%s\t%s\n", "username", "password");
	for(i = 0; i<5+m; i++){
		fprintf(file, "%s\t%s\n", p->username, p->password );
		p = p->Next;
	} 
	fclose(file);
	printf("Users are successfully stored!\n");
	return 0;
} 
