#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rule.h"
#include "extra.h"
#include "game.h"

// Function implementations for the number guessing game
int generateRandomNumber()
{
    srand(time(NULL));              // Seed the random number generator
    return rand() % MAX_NUMBER + 1; // Generate a random number between 1 and 100
}

// Function to set the difficulty level based on user input
enum Difficulty setDifficulty()
{
    // This function will be implemented to set the difficulty level based on user input
    printf("%s\n%s\n%s\n%s\n\n",
           "Please select the difficulty level:",
           "1. Easy (10 chances)",
           "2. Medium (5 chances)",
           "3. Hard (3 chances)");

    printf("Enter your choice (1-3): ");
    int choice;
    validateInput(&choice, MIN_NUMBER, MAX_CHOICES); // Validate that the choice is between 1 and 3
    return choice - 1;                               // Adjust for 0-based indexing
}

// Function to set the number of chances based on the selected difficulty level
int setChances(enum Difficulty difficultyLevel)
{
    switch (difficultyLevel)
    {
    case EASY:
        return 10;
    case MEDIUM:
        return 5;
    case HARD:
        return 3;
    default:
        return 10; // Default to easy if something goes wrong
    }
}

// Function to handle the main game logic
int playGame(int numberToGuess, time_t startTime, enum Difficulty difficultyLevel)
{
    int chances = setChances(difficultyLevel); // Get the number of chances based on the selected difficulty level

    printf("\nGreat! You've selected %s difficulty.\nLet's start the game!\n\n",
           difficultyLevel == EASY ? "Easy" : difficultyLevel == MEDIUM ? "Medium"
                                                                        : "Hard");

    for (int i = 0; i < chances; i++)
    {
        int guess;

        if (i >= chances * 0.60) // Provide a hint in the last 40% of chances
        {
            provideHint(numberToGuess);
        }

        printf("Enter your guess: ");
        validateInput(&guess, MIN_NUMBER, MAX_NUMBER); // Validate that the guess is between 1 and 100

        if (guess == numberToGuess)
        {
            printf("Congratulations! You guessed the correct number in %d attempts!\n\n", i + 1);
            showTimeTaken(startTime);                  // Show time taken after the game ends
            return calculateScore(difficultyLevel, i); // Return the score based on the difficulty level and attempts used
        }
        else if (guess < numberToGuess)
        {
            printf("Incorrect! The number is greater than %d.\n\n", guess);
        }
        else
        {
            printf("Incorrect! The number is less than %d.\n\n", guess);
        }
    }

    printf("Sorry, you've used all your chances. The number was %d.\n", numberToGuess);
    return 0; // No score if the player fails to guess the number
}
