#ifndef CONNECT_H
#define CONNECT_H

#define storage 40
#define title_size 40
#define author_size 40
#define min_search_align 5
#define standard_id 1000
#define max_id (standard_id + storage)

#define LINE2 "---------------------------------------------"
#define LINE "============================================="
typedef struct
{
    int ID;
    char title[40];
    char author[50];
    int status;
} template;

extern template Data[storage];

void addBook();
void searchBook();
void borrowBook();
void returnBook();
void displayBooks();
void saveBooks();
void loadBooks();

#endif