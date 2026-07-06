#ifndef UTIL_H
#define UTIL_H


#define Max_String 40
#define library_storage 40
#define Max_String 40
#define LINE "---------------------------------------------------------------------------------"
#define LINE2 "================================================================================="

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
    int borrowed_record;
} Book;
extern Book Library[library_storage];

int get_total_book();
void add_NewBook(char *title, char *author);
void saveBooks(int id, int status);
Book *loadBooks(int id);
Book *loadBooks_byString(char *str);

#endif