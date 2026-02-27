# Number Guessing Game

> A simple number guessing game to test your luck.

## Table of Contents

* [General Info](#general-information)
* [Technologies Used](#technologies-used)
* [Features](#features)
* [Setup](#setup)
* [How to play](#how-to-play)
* [Project Status](#project-status)
* [Acknowledgements](#acknowledgements)

## General Information

Number Guessing Game is a simple CLI-based game built with C where the computer randomly selects a number and the user has to guess it. This project is designed to explore and practice logic building and working with C programming language.

## Technologies Used

* C (C17/C18 standard)
* GCC (GNU Compiler Collection)
* Standard C Library

## Features

* **Difficulty Level**: Difficulty level options (easy, medium, hard) which will determine the number of chances they get to guess the number.
* **Hint System**: Provides clues to the user if they are stuck.
* **Multiple Round**: Asking the user if they want to play again after each round.
* **Timer**: Display a timer to see how long it takes the user to guess the number.
* **High Score**: Keep track of the user’s fewest attempts under a specific difficulty level.

## Setup

To run this CLI tool, you’ll need:

* GCC compiler
* Unix-like environment (Linux, macOS, WSL, etc.)

How to Build:

1. Clone the repository

   ```bash
   git clone https://github.com/krisnaajiep/number-guessing-game.git
   ```

2. Change the current working directory

   ```bash
   cd number-guessing-game
   ```

3. Compile the program

   ```bash
   gcc -Iinclude src/*.c -o guessnumber
   ```

4. Run the program

   ```bash
   ./guessnumber
   ```

## How to play

After launching the program, you will see a welcome message and instructions.

```bash
Welcome to the Number Guessing Game!
I'm thinking of a number between 1 and 100.
Can you guess it?
```

Choose a difficulty level:

```bash
Please select the difficulty level:
1. Easy (10 chances)
2. Medium (5 chances)
3. Hard (3 chances)

Enter your choice: 1
```

Enter guesses until you find the correct number.
Hints will appear after several incorrect attempts.

Example of a successful result:

```bash
Congratulations! You guessed the correct number in 7 attempts!

You took 10.00 seconds to guess the number.
New high score for Easy difficulty: 4/10
```

At the end, you can choose to play again.

## Project Status

Project is: _complete_.

## Acknowledgements

This project was inspired by [roadmap.sh](https://roadmap.sh/projects/number-guessing-game).
