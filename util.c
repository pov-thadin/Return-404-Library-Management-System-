#include <stdio.h>
#include <string.h>
#include <ctype.h>
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

int get_total_book(){
    int size = 0;
    for (int i = 0; i < library_storage; i++){
        if (Library[i].id != 0){
            size += 1;
        }
    }

    return size;
}

Book *loadBooks(int id){
    for (int i = 0; Library[i].id != 0; i++){
        if (Library[i].id == id){
            return &Library[i];
        }
    }
    return NULL;
}

Book *loadBooks_byString(char *str){
    for (int i = 0; Library[i].id != 0; i++){
        int max_title =  (int)strlen(Library[i].title) / 3;
        int max_author =  (int)strlen(Library[i].author) / 3;

        int success = 0;
        for (int ci = 0; Library[i].title[ci] != '\0' || success >= max_title; ci++){
            char ch = Library[i].title[ci];
            if (tolower(str[success]) == tolower(ch)){
                success += 1;
            }else{
                success = 0;
            }

            if (success >= max_title){
                return &Library[i];
            }
        }

        success = 0;
        for (int ci = 0; Library[i].author[ci] != '\0' || success >= max_author; ci++){
            char ch = Library[i].author[ci];
            if (tolower(str[success]) == tolower(ch)){
                success += 1;
            }else{
                success = 0;
            }

            if (success >= max_author){
                return &Library[i];
            }
        }
    }

    return NULL;
}