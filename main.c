#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

void showScore(char* result , int botScore , int userScore) {
    printf("\n%s!\n\nBot - %i  |  User - %i\n\n" , result , botScore , userScore);
}

int main() {
    srand(time(NULL));

    char userChoice[15];
    int botChoice;
    int userScore , botScore = 0;
    int convUserChoice;
    
    printf("Welcome to Rock Paper Scissors game!\n\n");

    while (true) {           // main loop
        convUserChoice = 0;
        printf("1. Rock\n2. Paper\n3. Scissors\n\nYour Choice: "); // Prompt user for a number
        fgets(userChoice , 13 , stdin);
        userChoice[strcspn(userChoice, "\n")] = 0; // Strip the newline at the end
        botChoice = rand() % 3 + 1;    // get random number
        printf("Bot Choice: %i" , botChoice);
        
        if (strcmp(userChoice , "rock") == 0 || strcmp(userChoice , "1") == 0){                 // Converting userChoice to a number 
            convUserChoice = 1;
        } else if (strcmp(userChoice , "paper") == 0 || strcmp(userChoice , "2") == 0){         
            convUserChoice = 2;
        } else if (strcmp(userChoice , "scissors") == 0 || strcmp(userChoice , "3") == 0){
            convUserChoice = 3;
        }

        switch (convUserChoice) {     // multiple events for different user/bot inputs
            case 1:
                if (botChoice == 1) {
                    showScore("Draw", botScore, userScore);
                    break;
                } else if (botChoice == 2) {
                    showScore("You Lose", botScore, userScore);
                    botScore++;
                    break;
                } else if (botChoice == 3) {
                    showScore("You Win", botScore, userScore);
                    userScore++;
                    break;
                }
            case 2:
                if (botChoice == 1) {
                    showScore("You Win", botScore, userScore);
                    userScore++;
                    break;
                } else if (botChoice == 2) {
                    showScore("Draw", botScore, userScore);
                    break;
                } else if (botChoice == 3) {
                    showScore("You Lose", botScore, userScore);
                    botScore++;
                    break;
                }
            case 3:
                if (botChoice == 1) {
                    showScore("You Lose", botScore, userScore);
                    botScore++;
                    break;
                } else if (botChoice == 2) {
                    showScore("You Win", botScore, userScore);
                    userScore++;
                    break;
                } else if (botChoice == 3) {
                    showScore("Draw", botScore, userScore);
                    break;
                }
            default:
                printf("\nUnknown Choice!\n\n");
        }
}   
    return 0;
}