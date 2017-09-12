#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>



int main() {

    char str[100];
    srand((unsigned int)time(NULL));

    printf("Welcome to Rock, Paper, Scissors\n \nWould you like to play? ");

    scanf("%s", &str);

    /*printf("Entered string is %s \n", str);*/

    return 0;
}

/*int value = rand() % (high - low + 1) + low;*/