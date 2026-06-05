#include <stdio.h>
#include <string.h>
#include "connector.h"
#include <ctype.h>


int search_by_code(int code);
int search_by_str(char *str);

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
    Data[set].ID = 1000 + set;
    strcpy(Data[set].title, title);
    strcpy(Data[set].author, author);
}

void delete(int index){
    Data[index].ID = 0;
    strcpy(Data[index].title, "");
    strcpy(Data[index].author, "");
}

void view(){
    printf("\n%s", LINE);
    for (int i = 0; Data[i].ID != 0; i++){
        printf("\n%s\nID: %i | Title: %s | Author: %s",LINE, Data[i].ID, Data[i].title, Data[i].author);
    }
}

void search(){
    printf("\n%s", LINE);
    printf("\nEnter code, title or author: ");
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
    

    printf("%i", index);
    if (index != -1){
        printf("\nFound: ");
        printf("ID: %i | Title: %s | Author: %s", Data[index].ID, Data[index].title, Data[index].author);
    }else{
        printf("\nNot found");
    }
}

int search_by_str(char *str){
    int index = -1;
    int n1 = 0;

    for (int i = 0; Data[i].ID != 0 || index != -1; i ++){
        char match_text[title_size];
        strcpy(match_text, Data[i].title);

        for (int ci = 0; match_text[ci] != '\0'; ci++){
            if (tolower(str[n1]) == tolower(match_text[ci])){
                printf("%c :: %c", str[n1], match_text[ci]);
                n1 += 1;
                if (n1 >= min_search_align){
                    index = i;
                    break;
                }
            }else{
                n1 = 0;
            }
        }
    }
    n1 = 0;
    if (index == -1){
        for (int i = 0; Data[i].ID != 0 || index != -1; i ++){
            char match_text[author_size];
            strcpy(match_text, Data[i].author);
            for (int ci = 0; match_text[ci] != '\0'; ci++){
                if (tolower(str[n1]) == tolower(match_text[ci])){
                    n1 += 1;
                    if (n1 >= min_search_align){
                        index = i;
                        break;
                    }
                }else{
                    n1 = 0;
                }
            }
        }
    }

    return index;
}

int search_by_code(int code){
    int index = -1;
    for (int i = 0; Data[i].ID != 0; i ++){
        if (Data[i].ID == code){
            index = i;
            break;
        }
    }

    return index;
}