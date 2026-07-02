#include <stdio.h>
#include <string.h>
#include "util.h"

void add_NewBook(char *title, char *author){
    int i = 0;
    for (i; i < library_storage; i++){
        if (Library[i].id == 0){
            break;
        }
    }

    Library[i].id = 1000 + i;
    strcpy(Library[i].title, title);
    strcpy(Library[i].author, author);
}

void saveBooks(int id, int status){
    Book *BookToSave = loadBooks(id);
    BookToSave->status = (Book_Status)status;
}

Book *loadBooks(int id){
    for (int i = 0; Library[i].id != 0; i++){
        if (Library[i].id == id){
            return &Library[i];
        }
    }
    return NULL;
}