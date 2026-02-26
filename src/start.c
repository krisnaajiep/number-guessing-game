#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "rule.h"
#include "game.h"
#include "start.h"

// Function to update the high score for the selected difficulty level
void updateHighScore(enum Difficulty difficultyLevel, int score, int *highScore)
{
    if (score > *highScore)
    {
        *highScore = score;
        printf("New high score for %s difficulty: %d/10\n",
               difficultyLevel == EASY ? "Easy" : difficultyLevel == MEDIUM ? "Medium"
                                                                            : "Hard",
               score);
    }
}

// Function to start the number guessing game
void startGame()
{
    printf("%s\n%s\n%s\n\n",
           "Welcome to the Number Guessing Game!",
           "I'm thinking of a number between 1 and 100.",
           "Can you guess it?");

    bool replay = false;          // Variable to control the replay loop
    int highScore[3] = {0, 0, 0}; // Initialize high scores for each difficulty level

    do
    {
        int numberToGuess = generateRandomNumber();                        // Generate a random number to guess
        DEBUG_PRINT("\nGenerated number to guess: %d\n\n", numberToGuess); // Debug print for the generated number

        enum Difficulty difficultyLevel = setDifficulty(); // Set the difficulty level based on user input

        time_t startTime = time(NULL);                                        // Start the timer
        int score = playGame(numberToGuess, startTime, difficultyLevel);      // Play the game and get the score based on remaining chances
        updateHighScore(difficultyLevel, score, &highScore[difficultyLevel]); // Update high score for the selected difficulty level

        printf("\nDo you want to play again? (y/n): ");
        char input[10];
        fgets(input, sizeof(input), stdin);

        if (input[0] == 'y' || input[0] == 'Y')
        {
            replay = true; // Set replay to true to start a new game
        }
        else
        {
            replay = false; // Set replay to false to exit the game
            printf("\nThanks for playing!\n");
        }
    } while (replay);
}