#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

enum choice { rock = 1, paper, scissors };

void set_console_color(int text, int bg) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bg << 4) | text);
}

choice get_computer_choice() {
    int choice_int = rand() % 3 + 1;
    return static_cast<choice>(choice_int);
}

string determine_winner(choice player_choice, choice computer_choice) {
    if (player_choice == computer_choice) return "Draw";
    if ((player_choice == rock && computer_choice == scissors) ||
        (player_choice == paper && computer_choice == rock) ||
        (player_choice == scissors && computer_choice == paper)) {
        return "Player";
    }
    return "Computer";
}

void play_round(int round_number, int& player_score, int& computer_score) {
    cout << "\nRound " << round_number << " - Player vs Computer" << endl;

    int player_input;
    cout << "Enter your choice (1 for rock, 2 for paper, 3 for scissors): ";
    cin >> player_input;
 
    while (player_input < 1 || player_input > 3) {
        cout << "Invalid choice. Please enter 1 for rock, 2 for paper, or 3 for scissors: ";
        cin >> player_input;
    }

    choice player_choice = static_cast<choice>(player_input);

    choice computer_choice = get_computer_choice();
    cout << "Computer chose: " << (computer_choice == rock ? "rock" : computer_choice == paper ? "paper" : "scissors") << endl;

    string winner = determine_winner(player_choice, computer_choice);
    if (winner == "Player") {
        ++player_score;
        set_console_color(10, 0);
        cout << "You win this round!" << endl;
        Beep(1000, 500);
    } else if (winner == "Computer") {
        ++computer_score;
        set_console_color(12, 0);
        cout << "Computer wins this round!" << endl;
        Beep(750, 300);
    } else {
        set_console_color(14, 0);
        cout << "This round is a draw!" << endl;
        Beep(500, 200);
    }

    set_console_color(15, 0);
}

void display_final_scores(int player_score, int computer_score) {
    cout << "\nGame Over!" << endl;
    cout << "Final Scores:" << endl;
    cout << "Player: " << player_score << endl;
    cout << "Computer: " << computer_score << endl;

    if (player_score > computer_score) {
        cout << "Congratulations! You won the game!" << endl;
    } else if (computer_score > player_score) {
        cout << "Computer won the game. Better luck next time!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
}

void start_game() {
    srand(time(0));

    char play_again;

    do {
        int rounds;
        cout << "Enter the number of rounds: ";
        cin >> rounds;

        int player_score = 0, computer_score = 0;

        for (int i = 1; i <= rounds; ++i) {
            play_round(i, player_score, computer_score);
        }

        display_final_scores(player_score, computer_score);

        cout << "\nDo you want to play again? (y/n): ";
        cin >> play_again;

    } while (play_again == 'y' || play_again == 'Y');

    cout << "Thank you for playing!" << endl;
}

int main() {
    start_game();
    return 0;
}