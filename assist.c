#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "connector.h"
#include "assist.h"

int search_by_str(char *str){
    int index = -1;
    int n1 = 0;
    for (int i = 0; Data[i].ID != 0; i ++){
        char match_text[title_size];
        strcpy(match_text, Data[i].title);

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
            if (index != -1){
                break;
            }
        }
    }

    if (index == -1){
        for (int i = 0; Data[i].ID != 0; i ++){
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
                if (index != -1){
                    break;
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

int generate_id(){
    int code = -1;
    for (int n = standard_id; n <= max_id; n++){
        int b = 0;
        for (int i; Data[i].ID != 0; i++){
            if (Data[i].ID == n){
                b = 1;
                break;
            }
        }

        if (b == 0){
            code = n;
            break;
        }
    }
    return code;
}

void arrange_data(int from_index){
    int ci = 0;
    for (int current_index = from_index + 1; Data[current_index].ID != 0; current_index ++){
        int set_index = current_index - 1;
        Data[set_index].ID = Data[current_index].ID;
        Data[set_index].status = Data[current_index].status;
        strcpy(Data[set_index].title, Data[current_index].title);
        strcpy(Data[set_index].author, Data[current_index].author);
        ci = current_index;
    }

    Data[ci].ID = 0;
    Data[ci].status = 0;
    strcpy(Data[ci].title, "");
    strcpy(Data[ci].author, "");
}

int get_index_by_search(char *input){
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

    int index = -1;
    if (v == 3){
        printf("\n Invalid variable!");
    }else if (v == 1) //by int
    {
        index = search_by_code(code);
    }else{  //by str
        index = search_by_str(input);
    }

    return index;
}