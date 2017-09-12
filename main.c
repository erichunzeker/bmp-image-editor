#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <memory.h>


int main() {

    char str[10];
    char yes[]="yes";
    char no[]="no";
    char rock[]="rock";
    char paper[]="paper";
    char scissors[]="scissors";



    srand((unsigned int)time(NULL));


    printf("Welcome to Rock, Paper, Scissors\n \n");

    do {
        printf("Would you like to play? "); //check if player wants to play, validate input

        scanf("%s", &str);
    }while (strcmp(str,yes)!=0 && strcmp(str,no)!=0);

    if(strcmp(str,no)==0)
    {
        printf("Goodbye"); //if player says no, quit
        return 0;
    }

    int playerScore = 0;
    int compScore = 0;

    while(playerScore < 3 && compScore < 3)
    {
        do {
            printf("What is your choice? "); //player picks move

            scanf("%s", &str);


        }while (strcmp(str,rock)!=0 && strcmp(str,paper)!=0 && strcmp(str,scissors)!=0);

        int value = rand() % (3 - 1 + 1) + 1;

        char compMove[10];

        if(value == 1)
            strcpy(compMove, "rock");
        else if(value == 2)
            strcpy(compMove, "paper");
        else
            strcpy(compMove, "scissors");

        printf("\nThe computer chooses %s. ", compMove);

        if(strcmp(str, compMove)==0)
            printf("It is a tie. \n");
        else if()


    }

    /*printf("Entered string is %s \n", str);*/

    return 0;
}




