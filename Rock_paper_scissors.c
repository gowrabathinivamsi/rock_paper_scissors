#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

void printChoice(int choice) {
    if (choice == ROCK)
        printf("Rock\n");
    else if (choice == PAPER)
        printf("Paper\n");
    else if (choice == SCISSORS)
        printf("Scissors\n");
}

int main() {
    int userChoice, computerChoice;
    
    // Seed the random number generator
    srand(time(0));
    
    printf("Rock, Paper, Scissors Game\n");
    printf("Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ");
    scanf("%d", &userChoice);
    
    // Validate user input
    if (userChoice < 1 || userChoice > 3) {
        printf("Invalid choice! Please choose 1, 2, or 3.\n");
        return 1;
    }

    // Generate computer's choice randomly
    computerChoice = rand() % 3 + 1;

    printf("\nYou chose: ");
    printChoice(userChoice);

    printf("Computer chose: ");
    printChoice(computerChoice);
    
    // Determine the winner
    if (userChoice == computerChoice) {
        printf("\nIt's a tie!\n");
    } else if ((userChoice == ROCK && computerChoice == SCISSORS) ||
               (userChoice == PAPER && computerChoice == ROCK) ||
               (userChoice == SCISSORS && computerChoice == PAPER)) {
        printf("\nYou win!\n");
    } else {
        printf("\nComputer wins!\n");
    }

    return 0;
}

