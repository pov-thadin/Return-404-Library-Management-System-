#ifndef UTIL_H
#define UTIL_H


#define Max_String 40
#define library_storage 40
#define Max_String 40
#define LINE "--------------------------------------"

typedef enum{
    BORROWED,
    AVAILABLE
} Book_Status;

typedef struct 
{
    int id;
    char title[Max_String];
    char author[Max_String];
    Book_Status status;
} Book;
extern Book Library[library_storage];


void add_NewBook(char *title, char *author);
void saveBooks(int id, int status);
Book *loadBooks(int id);

#endif