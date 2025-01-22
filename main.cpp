#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> // For setting console colors

using namespace std;

// Enum for choices
enum Choice { Rock = 1, Paper, Scissors };

// Function to set console text and background colors
void setConsoleColor(int text, int background) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (background << 4) | text);
}

// Function to get computer's choice
Choice getComputerChoice() {
    int choice = rand() % 3 + 1; // Random number between 1 and 3
    return static_cast<Choice>(choice);
}

// Function to determine the winner of a round
string determineWinner(Choice playerChoice, Choice computerChoice) {
    if (playerChoice == computerChoice) return "Draw";
    if ((playerChoice == Rock && computerChoice == Scissors) ||
        (playerChoice == Paper && computerChoice == Rock) ||
        (playerChoice == Scissors && computerChoice == Paper)) {
        return "Player";
    }
    return "Computer";
}

// Function to play a single round
void playRound(int roundNumber, int& playerScore, int& computerScore) {
    cout << "\nRound " << roundNumber << " - Player vs Computer" << endl;

    // Get player choice
    int playerInput;
    cout << "Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ";
    cin >> playerInput;

    // Validate player choice
    while (playerInput < 1 || playerInput > 3) {
        cout << "Invalid choice. Please enter 1 for Rock, 2 for Paper, or 3 for Scissors: ";
        cin >> playerInput;
    }

    Choice playerChoice = static_cast<Choice>(playerInput);

    // Get computer choice
    Choice computerChoice = getComputerChoice();
    cout << "Computer chose: " << (computerChoice == Rock ? "Rock" : computerChoice == Paper ? "Paper" : "Scissors") << endl;

    // Determine the winner
    string winner = determineWinner(playerChoice, computerChoice);
    if (winner == "Player") {
        ++playerScore;
        setConsoleColor(10, 0); // Green text
        cout << "You win this round!" << endl;
        Beep(1000, 500); // Ring a bell sound
    } else if (winner == "Computer") {
        ++computerScore;
        setConsoleColor(12, 0); // Red text
        cout << "Computer wins this round!" << endl;
        Beep(750, 300); // Ring a bell sound
    } else {
        setConsoleColor(14, 0); // Yellow text
        cout << "This round is a draw!" << endl;
        Beep(500, 200); // Ring a bell sound
    }

    setConsoleColor(15, 0); // Reset to default color
}

// Function to display final scores and determine the overall winner
void displayFinalScores(int playerScore, int computerScore) {
    cout << "\nGame Over!" << endl;
    cout << "Final Scores:" << endl;
    cout << "Player: " << playerScore << endl;
    cout << "Computer: " << computerScore << endl;

    if (playerScore > computerScore) {
        cout << "Congratulations! You won the game!" << endl;
    } else if (computerScore > playerScore) {
        cout << "Computer won the game. Better luck next time!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
}

// Function to start and manage the game loop
void StartGame() {
    srand(time(0)); // Seed for random number generation

    char playAgain;

    do {
        // Ask for the number of rounds
        int rounds;
        cout << "Enter the number of rounds: ";
        cin >> rounds;

        int playerScore = 0, computerScore = 0;

        // Play the specified number of rounds
        for (int i = 1; i <= rounds; ++i) {
            playRound(i, playerScore, computerScore);
        }

        // Display final scores and winner
        displayFinalScores(playerScore, computerScore);

        // Ask if the user wants to play again
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!" << endl;
}

int main() {
    StartGame();
    return 0;
}