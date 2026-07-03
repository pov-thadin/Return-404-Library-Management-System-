#include <stdio.h>
#include "util.h"
#include <string.h>
#include <stdbool.h>


void addBook(){
    char title[Max_String];
    char author[Max_String];
    printf("\n%s", LINE);
    printf("\nEnter Book Title: ");        
    fgets(title, Max_String, stdin);

    printf("Enter Author Name: ");
    fgets(author, Max_String, stdin);
    printf("\n%s", LINE);
    // Remove '\n' added by fgets
    title[strcspn(title, "\n")] = '\0';
    author[strcspn(author, "\n")] = '\0';

    // Built-in function
    add_NewBook(title, author);

    printf("\nBook added successfully!");
}

void searchBook(){
    char input[Max_String];
    printf("\n%s", LINE);
    printf("\nEnter book's ID/Title/Author: ");
    fgets(input, Max_String, stdin);
    input[strcspn(input, "\n")] = '\0';

    int id = 0;
    bool IsNumber = true;
    for (int i = 0; input[i] != '\0' || IsNumber == false; i++){
        if (input[i] >= '0' && input[i] <= '9' && IsNumber == true){
            id = (id * 10) + (input[i] - '0');
            printf("%i", id);
        }else{
            IsNumber = false;
            break;
        }
    }
    Book *book = (IsNumber == true)? loadBooks(id) : loadBooks_byString(input);

    if (book != NULL){
        printf("\n%s", LINE);
        printf("\nBook Founded:  ID: %-6d Title: %-25s Author: %-25s Status: %-10s Borrowed Record: %-6d",
            book->id,
            book->title,
            book->author,
            (book->status == AVAILABLE)? "Available" : "Borrowed",
            book->borrowed_record
        );
    }else{
        printf("\nBook not Founded!");
    }
    
} 
void borrowBook(){
    int id;
    printf("\n%s", LINE);
    printf("\nEnter book ID to borrow: ");
    scanf("%d",&id);
    printf("\n%s", LINE);

    Book *book = loadBooks(id);

    if(book==NULL){
        printf("\nBook not found!");
        return;
    }

    if(book->status==BORROWED){
        printf("\nBook is unavailable.");
    }else{
        book->borrowed_record += 1;
        book->status=BORROWED;
        printf("\nBook borrowed successfully.");
    }
}
void returnBook(){
    int id;
    printf("\n%s", LINE);
    printf("\nEnter book ID to return: ");
    scanf("%d",&id);
    printf("\n%s", LINE);
    Book *book = loadBooks(id);

    if(book==NULL){
        printf("\nBook not found!");
        return;
    }

    if(book->status==AVAILABLE){
        printf("\nBook is already available.");
    }else{
        book->status=AVAILABLE;
        printf("\nBook returned successfully.");
    }
} 
void displayBooks(){
    int opt;
    printf("\n%s", LINE);
    printf("\n1. view all\n2. view borrowed\n3. view available\nEnter Option: ");
    scanf("%i", &opt);
    printf("\n%s", LINE);
    printf("\n|%-6s|%-25s|%-25s|%-10s|", "ID", "Title", "Author", "Status");
    printf("\n%s", LINE);

    if (opt >= 1 && opt <= 3){
        for (int i = 0; i < library_storage; i++){
            if (Library[i].id == 0)
                continue;
            if (opt == 1 || Library[i].status == opt - 2){
                printf("\n|%-6d|%-25s|%-25s|%-10s|",
                Library[i].id,
                Library[i].title,
                Library[i].author,
                (Library[i].status == AVAILABLE) ? "Available" : "Borrowed");
            }
        }
    }else{
        printf("\nInvalid Option!");
    }

    printf("\n%s", LINE);
}