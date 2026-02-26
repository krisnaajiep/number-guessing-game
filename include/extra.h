#ifndef EXTRA_H
#define EXTRA_H

#include "rule.h"
#include <time.h>

void validateInput(int *input, int min, int max);
void provideHint(int numberToGuess);
void showTimeTaken(time_t startTime);
int calculateScore(enum Difficulty difficultyLevel, int attemptsUsed);

#endif // EXTRA_H