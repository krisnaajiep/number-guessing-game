#ifndef START_H
#define START_H

#ifdef DEBUG
#define DEBUG_PRINT(...)              \
    do                                \
    {                                 \
        fprintf(stderr, __VA_ARGS__); \
    } while (0)
#else
#define DEBUG_PRINT(...) \
    do                   \
    {                    \
    } while (0)
#endif

#include "rule.h"

void updateHighScore(enum Difficulty difficultyLevel, int score, int *highScore);
void startGame();

#endif // START_H