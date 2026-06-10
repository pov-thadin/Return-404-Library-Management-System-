#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "connector.h"
#include "assist.h"

char status_type [2][20] = {"Barrowed", "Available"};

void addBook(){
    printf("\n%s", LINE);

    char title[title_size], author[author_size];
    printf("\nEnter book's title: ");
    fgets(title, title_size, stdin);
    printf("\nEnter book's author: ");
    fgets(author, author_size, stdin);

    title[strcspn(title, "\n")] = '\0';
    author[strcspn(author, "\n")] = '\0';

    int index = get_data_size();

    strcpy(Data[index].author, author);
    strcpy(Data[index].title, title);
    Data[index].ID = generate_id();
    Data[index].status = 1;
}
void searchBook(){
    printf("\n%s", LINE);
    char input[title_size];
    printf("\nEnter book's id/title/author: ");
    fgets(input, title_size, stdin);
    input[strcspn(input, "\n")] = '\0';
    int index = get_index_by_search(input);
    if (index != -1){
        printf("\nMatch Found: ID: %i | Title: %s | Author: %s | Status: %s", Data[index].ID, Data[index].title, Data[index].author, status_type[Data[index].status]);
    }else{
        printf("\nBook no found!");
    }
} 

void borrowBook(){
    char input[title_size];
    printf("\n%s", LINE);
    printf("\nEnter book's id/title/author: ");
    fgets(input, title_size, stdin);
    input[strcspn(input, "\n")] = '\0';
    int index = get_index_by_search(input);
    if (index != -1){
        if (Data[index].status == 1){
            Data[index].status = 0;
            printf("\n %s has been barrowed.", Data[index].title);
        }else{
            printf("\n %s is unavailable.", Data[index].title);
        }
    }else{
        printf("\nBook no found!");
    }

    
} 

void returnBook(){
    char input[title_size];
    printf("\n%s", LINE);
    printf("\nEnter book's id/title/author: ");
    fgets(input, title_size, stdin);
    input[strcspn(input, "\n")] = '\0';

    int index = get_index_by_search(input);
    if (index != -1){
        if (Data[index].status == 1){
            printf("\n %s has already been returned!.", Data[index].title);
        }else{
            Data[index].status = 1;
            printf("\n %s has been returned.", Data[index].title);
        }
    }
}   

void displayBooks(){
    printf("\n%s", LINE);
    char cmd[3] = {'1', '2', '3'};
    char cmd_list[3][15] = {"barrowed", "available", "all"};
    for (int i = 0; i < 3; i++){
        printf("\n%c. view %s books", cmd[i], cmd_list[i]);
    }
    int input;
    //int max_data_size = get_data_size();
    printf("\nEnter code: ");
    scanf("%i", &input);

    if (input >= 1 && input <= 3){
        input -= 1;
        for (int i = 0; Data[i].ID != 0; i++){
            int status = Data[i].status;
            if ((input != 2 && status == input)|| input == 2){
                printf("\nID: %i | Title: %s | Author: %s", Data[i].ID, Data[i].title, Data[i].author);
                if (input == 2){
                    printf(" | Status: %s", status_type[Data[i].status]);
                }
            }
        }
    }else{
        printf("\nInvalid value");
    }
    
}

void saveBooks(){

}

void loadBooks(){

}