#include <stdio.h>
#include <string.h>
#include "connector.h"
#include "assist.h"
#include <ctype.h>

char book_status[2][20] = {"Barrowed", "Available"};

void add(){
    printf("\n%s", LINE);
    int set = 0;
    for (int i = 0; i <= storage; i ++){
        if (Data[i].ID == 0){
            set = i;
            break;
        }
    }

    char title[title_size], author[author_size];
    printf("\nEnter book title: ");
    fgets(title, title_size, stdin);
    printf("\nEnter author: ");
    fgets(author, author_size, stdin);

    title[strcspn(title, "\n")] = '\0';
    author[strcspn(author, "\n")] = '\0';
    //------------------------
    Data[set].ID = generate_id();
    Data[set].status = 1;
    strcpy(Data[set].title, title);
    strcpy(Data[set].author, author);
}

void delete_book(){
    printf("\n%s", LINE);
    char input[title_size];
    printf("\nEnter book's id to remove: ");
    fgets(input, title_size, stdin);
    //-----------------------------
    int code = extract_int(input);
    if (code != -1){
        int index = get_book_index(code);
        if (index != -1){
            Data[index].ID = 0;
            Data[index].status = 0;
            strcpy(Data[index].title, "");
            strcpy(Data[index].author, "");

            arrange_data(index);
        }else{
            printf("\nInvalid code");
        }
    }else{
        printf("\nInvalid code");
    }
}

void set_status(){
    char ch;
    char input[title_size];
    printf("\n%s", LINE);
    printf("\nEnter book's id: ");
    fgets(input, title_size, stdin);
    int code = extract_int(input);
    if (code != -1){
        int index = get_book_index(code);
        if (index != -1){
            printf("\nEnter book status([0] Barrowed/ [1] Available): ");
            ch = getchar();
            if (ch == '0' || ch == '1'){
                Data[index].status = ch - '0';
            }else{
                printf("\nInvalid value");
            }
        }else{
            printf("\nBook not found");
        }
    }else{
        printf("\nInvalid id");
    }
    
}

void view(){
    printf("\n%s", LINE);

    for (int i = 0; Data[i].ID != 0; i++){
        printf("\nID: %i | Title: %s | Author: %s | status: %s", Data[i].ID, Data[i].title, Data[i].author, book_status[Data[i].status]);
        if (Data[i + 1].ID != 0){
            printf("\n%s", LINE2);
        }
    }
}

void search(){
    printf("\n%s", LINE);
    printf("\nEnter id or title of the book: ");
    char input[title_size];
    fgets(input, title_size, stdin);
    input[strcspn(input, "\n")] = '\0';
    //---------------------------
    int v = 0;
    int code = 0;
    for (int i = 0; input[i] != '\0'; i++){
        char ch = input[i];
        if (ch >= '0' && ch <= '9'){
            v = 1;
            code = code * 10 + (ch - '0');
        }else{
            if (v == 1 && input[i] != '\0'){
                v = 3;
                break;
            }
        }   
    }

    //----------------------------
    int index = -1;
    printf("%i", v);
    if (v == 3){
        printf("\n Invalid variable!");
    }else if (v == 1) //by int
    {
        index = search_by_code(code);
    }else{  //by str
        index = search_by_str(input);
    }
    

    if (index != -1){
        printf("\nFound: ");
        printf("ID: %i | Title: %s | Author: %s", Data[index].ID, Data[index].title, Data[index].author);
    }else{
        printf("\nNot found");
    }
}


//----------------------------------------------BUILT IN FUNCTION