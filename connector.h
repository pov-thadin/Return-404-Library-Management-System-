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


void view(void);
void delete_book(void);
void search(void);
void add(void);
void set_status(void);
extern template Data[storage];

#endif