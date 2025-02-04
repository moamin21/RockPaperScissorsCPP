# Rock-Paper-Scissors Game

A simple console-based **Rock-Paper-Scissors** game implemented in C++.

## Features
- Play against the computer in a specified number of rounds
- Choose between Rock, Paper, and Scissors
- Real-time round tracking and scoring
- Option to play multiple game sessions
- Input validation for player choices

## How to Play
1. Choose the total number of rounds you want to play
2. For each round, enter your choice:
   - `1` for Rock  
   - `2` for Paper  
   - `3` for Scissors
3. The computer will randomly select its choice
4. View the result of each round
5. See final scores at the end of the game

## Installation
1. Compile the program using a C++ compiler:
   ```bash
   g++ main.cpp -o RockPaperScissors
   ```
2. Run the compiled program:
   ```bash
   ./RockPaperScissors
   ```

## Requirements
- C++ compiler
- Windows OS (due to `<windows.h>` inclusion)

## Game Rules
- Rock beats Scissors
- Scissors beats Paper
- Paper beats Rock
- Matching choices result in a draw

## Example Gameplay
```plaintext
Enter the number of rounds: 3

Round 1 - Player vs Computer
Enter your choice (1 for rock, 2 for paper, 3 for scissors): 1
Computer chose: scissors
You win this round!

Round 2 - Player vs Computer
Enter your choice (1 for rock, 2 for paper, 3 for scissors): 2
Computer chose: rock
You win this round!

Round 3 - Player vs Computer
Enter your choice (1 for rock, 2 for paper, 3 for scissors): 3
Computer chose: scissors
This round is a draw!

Game Over!
Final Scores:
Player: 2
Computer: 0
Congratulations! You won the game!

Do you want to play again? (y/n):
```

## Contributing
1. Fork the repository
2. Create a new branch (`git checkout -b feature-name`)
3. Commit your changes (`git commit -m 'Add feature'`)
4. Push the branch (`git push origin feature-name`)
5. Open a pull request

## Code Structure
- `get_computer_choice()`: Generates random computer choice
- `determine_winner()`: Calculates round winner
- `play_round()`: Manages individual round gameplay
- `display_final_scores()`: Shows game results

## Notes
- Requires a Windows compiler due to `<windows.h>` header
- Uses `srand()` for random number generation
- Supports multiple game sessions with replay option