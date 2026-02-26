#include <stdio.h>
#include <time.h>
#include <math.h>
#include "rule.h"
#include "extra.h"

// Function to validate user input and ensure it's within the specified range
void validateInput(int *input, int min, int max)
{
    char buffer[MAX_INPUT_LENGTH];
    while (fgets(buffer, sizeof(buffer), stdin))
    {
        if (sscanf(buffer, "%d", input) == 1 && *input >= min && *input <= max)
        {
            break; // Valid input
        }
        else
        {
            printf("Invalid input. Please enter a number between %d and %d: ", min, max);
        }
    }
}

// Function to provide a hint to the player based on the number to guess
void provideHint(int numberToGuess)
{
    int lowerBound = numberToGuess - 5 > MIN_NUMBER ? numberToGuess - 5 : MIN_NUMBER; // Ensure lower bound is at least 1
    int upperbound = numberToGuess + 5 < MAX_NUMBER ? numberToGuess + 5 : MAX_NUMBER; // Ensure upper bound is at most 100
    printf("Hint: The number is between %d and %d.\n\n", lowerBound, upperbound);
}

// Function to show the time taken by the player to guess the number
void showTimeTaken(time_t startTime)
{
    time_t endTime = time(NULL);                     // End the timer
    double timeTaken = difftime(endTime, startTime); // Calculate the time taken in seconds
    printf("You took %.2f seconds to guess the number.\n", timeTaken);
}

// Function to calculate the score based on the difficulty level and remaining attempts
int calculateScore(enum Difficulty difficultyLevel, int attemptsUsed)
{
    int score;

    switch (difficultyLevel)
    {
    case EASY:
        score = 10 - attemptsUsed; // Score based on remaining chances for easy difficulty
        break;
    case MEDIUM:
        score = 10 - attemptsUsed * 2; // Score based on remaining chances for medium difficulty
        break;
    case HARD:
        score = 10 - attemptsUsed * 3; // Score based on remaining chances for hard difficulty
        break;
    default:
        score = 0; // Default score if something goes wrong
        break;
    }

    return score;
}