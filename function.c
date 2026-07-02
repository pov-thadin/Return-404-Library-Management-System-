#include <stdio.h>
#include "util.h"
void addBook(){

}
void searchBook(){

} 
void borrowBook(){

}
void returnBook(){
    int id;

    printf("Enter book ID to return: ");
    scanf("%d",&id);

    Book *book = loadBooks(id);

    if(book==NULL){
        printf("Book not found!\n");
        return;
    }

    if(book->status==AVAILABLE){
        printf("Book is already available.\n");
    }else{
        book->status=AVAILABLE;
        printf("Book returned successfully.\n");
    }
} 
void displayBooks(){

}