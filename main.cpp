/*
 * This is a rock paper scissors program!
 * The user inputs their choice, the program
 * generates a choice, and they are compared to
 * see who wins.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void game();
void winner(int user, int computer);

int main() {
  cout << "Welcome to Rock, Paper, Scissors!\n" << endl;

  while(true) {
    // Start game
    game();
    cout << endl;

    // Asks user if they want to play again
    cout << "Would you like to play again? (y/n)" << endl;
    char choice;
    cin >> choice;

    // Checks if user responded with a valid answer
    while (true) if (choice == 'y' || choice == 'n') break;
    if (choice == 'n') break;
    cout << endl;
  }
  
  return 0;
}

void game() {
  int u;
  int c;

  // Computer choice
  srand(time(NULL));
  c = rand() % 3;

  // User choice
  while(true) {
    cout << "Your options: " << endl;
    cout << "1. Rock\n2. Paper\n3. Scissors\n> ";
    cin >> u;

    if (u >= 1 && u <= 3) break;
    cout << "That is not an option. Try again." << endl;
  }

  cout << endl;
  u--;

  winner(u, c);
}

void winner(int user, int computer) {
  // Checks for tie
  if (user == computer) {
    cout << "It's a tie." << endl;
    return;
  }

  // Compares computer and user choice
  switch (computer) {
    // Computer chooses rock
    case 0:
      // User chooses paper
      if (user == 1) cout << "You win! Computer chose rock.\n";
      // User chooses scissors
      else cout << "You lose. Computer chose rock\n";
      break;
    // Computer chooses paper
    case 1:
      // User chooses rock
      if (user == 0) cout << "You lose. Computer chose paper.\n";
      // User chooses scissors
      else cout << "You win! Computer chose paper.\n";
      break;
    // Computer chooses scissors
    case 2:
      // User chooses rock
      if (user == 0) cout << "You win! Computer chose scissors.\n";
      // User chooses scissors
      else cout << "You lose. Computer chose scissors.\n";
      break;
    // Error occurs
    default:
      cout << "An unknown error occured.\n";
  }
}
