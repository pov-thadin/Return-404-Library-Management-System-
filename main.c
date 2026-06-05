#include <stdio.h>
#include "connector.h"

#define cmd_size 5

char cmd[cmd_size] = {'1', '2', '3', '4', '5'};
char cmd_text[cmd_size][20] = {
    "view",
    "set status",
    "search",
    "add",
    "delete"
};

int main(){
    int run = 0;
    while (run == 0)
    {   
        char input;
        printf("\n%s", LINE);
        for (int i = 0; i < cmd_size; i ++){
            printf("\n%c. %s", cmd[i], cmd_text[i]);
        }
        printf("\n%s", LINE);
        printf("\n Enter code: ");
        input = getchar();
        while (getchar() != '\n');
        switch (input)
        {
        case '1':
            view();
            break;
        case '2':
            set_status();
            break;
        case '3':
            search();
            break;
        case '4':
            add();
            break;
        case '5':
            delete_book();
            break;
        default:
        printf("\n%s", LINE);
            printf("\nInvalid code");
            break;
        }
    }
    
    return 0;
}
