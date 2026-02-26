#ifndef NUMBER_GUESSING_GAME_H
#define NUMBER_GUESSING_GAME_H

#include "rule.h"
#include <time.h>

int generateRandomNumber();
enum Difficulty setDifficulty();
int setChances(enum Difficulty difficultyLevel);
int playGame(int numberToGuess, time_t startTime, enum Difficulty difficultyLevel);

#endif // NUMBER_GUESSING_GAME_H