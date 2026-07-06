#include <stdio.h>
#include <string.h>

#include "function.h"
#include "util.h"
//CONST DATA
#define cmd_size 6
//COMMAND
char cmd[cmd_size] = {'1', '2', '3', '4', '5', '6'};
char cmd_text[cmd_size][20] = {
    "view book",
    "search book",
    "borrow book",
    "return book",
    "add book",
    "Exit"
};

int main(){

    int run = 0;
    while (run == 0)
    {   
        int input;
        printf("\n%s", LINE2);
        for (int i = 0; i < cmd_size; i ++){
            printf("\n%c. %s", cmd[i], cmd_text[i]);
        }

        printf("\n%s", LINE2);
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
            break;
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
            run = 1;
            break;
        default:
        printf("\n%s", LINE);
            printf("\nInvalid code");
            break;
        }
    }

    return 0;
}
