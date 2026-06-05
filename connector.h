#ifndef CONNECT_H
#define CONNECT_H

#define storage 40
#define title_size 40
#define author_size 40
#define min_search_align 5
#define LINE "============================================="
typedef struct
{
    int ID;
    char title[40];
    char author[50];
    char status[10];
} template;

void view(void);
void delete(int index);
void search(void);
void add();
extern template Data[storage];

#endif