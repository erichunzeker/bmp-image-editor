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


    printf("Welcome to Rock, Paper, Scissors\n");

    do {
        printf("Would you like to play? "); //check if player wants to play, validate input

        scanf("%s", &str);
    }while (strcmp(str,yes)!=0 && strcmp(str,no)!=0);

    if(strcmp(str,no)==0)
    {
        printf("Goodbye"); //if player says no, quit
        return 0;
    }

    do {
        int playerScore = 0;
        int compScore = 0;

        while (playerScore < 3 && compScore < 3) {
            do {
                printf("\nWhat is your choice? "); //player picks move

                scanf("%s", &str);


            } while (strcmp(str, rock) != 0 && strcmp(str, paper) != 0 && strcmp(str, scissors) != 0);

            int value = rand() % (3 - 1 + 1) + 1;

            char compMove[10];

            if (value == 1)
                strcpy(compMove, "rock");
            else if (value == 2)
                strcpy(compMove, "paper");
            else
                strcpy(compMove, "scissors");

            printf("The computer chooses %s. ", compMove);

            if (strcmp(str, compMove) == 0)
                printf("It is a tie. \n");


            else if (strcmp(compMove, rock) == 0 && strcmp(str, paper) == 0) {
                printf("You win this game! \n");
                playerScore++;
            } else if (strcmp(compMove, paper) == 0 && strcmp(str, scissors) == 0) {
                printf("You win this game! \n");
                playerScore++;
            } else if (strcmp(compMove, scissors) == 0 && strcmp(str, rock) == 0) {
                printf("You win this game! \n");
                playerScore++;
            } else if (strcmp(compMove, paper) == 0 && strcmp(str, rock) == 0) {
                printf("You lose this game! \n");
                compScore++;
            } else if (strcmp(compMove, scissors) == 0 && strcmp(str, paper) == 0) {
                printf("You lose this game! \n");
                compScore++;
            } else if (strcmp(compMove, rock) == 0 && strcmp(str, scissors) == 0) {
                printf("You lose this game! \n");
                compScore++;
            }

            printf("\nThe score is now you: %d computer: %d\n", playerScore, compScore);

        }

        if (playerScore > compScore)
            printf("\nYou win the game\n");
        else
            printf("\nYou lose the game\n");

        do {
            printf("\nWould you like to play again? "); //check if player wants to play, validate input

            scanf("%s", &str);
        }while (strcmp(str,yes)!=0 && strcmp(str,no)!=0);

    }while(strcmp(str,yes)==0);

    printf("\nGoodbye");

    return 0;
}




