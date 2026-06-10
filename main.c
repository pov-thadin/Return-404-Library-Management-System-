#include <stdio.h>
#include "connector.h"

#define cmd_size 6

char cmd[cmd_size] = {'1', '2', '3', '4', '5', '6'};
char cmd_text[cmd_size][20] = {
    "view",
    "search",
    "barrow",
    "return",
    "add",
    "delete"
};

int main(){
    int run = 0;
    while (run == 0)
    {   
        int input;
        printf("\n%s", LINE);
        for (int i = 0; i < cmd_size; i ++){
            printf("\n%c. %s", cmd[i], cmd_text[i]);
        }

        printf("\n%s", LINE);
        printf("\n Enter code: ");
        scanf("%i", &input);
        getchar();
        switch (input)
        {
        case 1:
            displayBooks();
            break;
        case 2:
            searchBook();
        case 3:
            borrowBook();
            break;
        case 4:
            returnBook();
            break;
        case 5:
            addBook();
            break;
        case 6:
        
            break;
        default:
        printf("\n%s", LINE);
            printf("\nInvalid code");
            break;
        }
    }
    
    return 0;
}
