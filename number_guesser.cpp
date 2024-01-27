#include "utils.h"
#include <cstdio>
#include <iostream>
#include <time.h>

int min, max, max_tries = 10, wins = 0, rounds = 1;
bool game_over = false;
int secret;

int gen_secret_number(int min = 0, int max = 100) {
  time_t current_time = time(NULL);
  srand((unsigned)current_time);
  int random = min + rand() % ((max - min) + 1);
  return random;
}

void reset_game() {
  min = gen_secret_number();
  max = gen_secret_number(min);
  secret = gen_secret_number(min, max);
  max_tries = 10;
}

void play_another_round() {
  bool confirm = yes_no_input("Would you like to play again? (Y/n): ");

  if (confirm) {
    rounds++;
    reset_game();
    std::cout << "Starting round " << rounds << " ...\n\n";
  } else {
    game_over = true;
  }
}


int main() {
  reset_game();

  std::cout << "Welcome to number guesser!" << std::endl;
  std::cout << "You have " << max_tries
            << " tries in each round to guess the secret number.\n\n"
            << std::endl;

  std::cout << "Starting round " << rounds << " ..." << std::endl;

  while (!game_over) {
    char msg[100];
    sprintf(msg, "Guess the secret number between %d and %d: ", min, max);
    int guess = input<int>(msg, min, max);

    if (guess != secret) {
      std::string clue = guess > secret ? "You guessed too high ... Go lower"
                                        : "You guessed too low ... Go higher";
      std::cout << clue << std::endl;

      max_tries--;

      // Start warning user about remaining guesses when limit is approaching
      if (max_tries < 4) {
        std::cout << max_tries << " guesses left!" << std::endl;
      }

      if (max_tries == 0) {
        std::cout << "Game Over! You failed this round :(\n" << std::endl;
        std::cout << "The secret number was " << secret << std::endl;
        play_another_round();
      }

    } else {
      std::cout << "Very good guess. The secret number is in fact " << secret
                << "\n\n";
      wins++;
      play_another_round();
    }

    std::cout << "\n";
  }

  // Display game results
  char msg[100];
  sprintf(msg, "%s You have won %d out of %d rounds of number guesser",
          wins > 0 ? "Hurray!" : "Sadly ...", wins, rounds);
  std::cout << msg << std::endl;

  std::cout << "Exiting program. Bye!" << std::endl;
  return 0;
}