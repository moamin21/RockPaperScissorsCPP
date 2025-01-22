# Rock-Paper-Scissors Game

A simple console-based **Rock-Paper-Scissors** game implemented in C++ with colorful visuals, sound effects, and a user-friendly experience.

## Features
- Play against the computer in a specified number of rounds.
- Real-time feedback with colored text and sound effects.
- Displays scores and announces the overall winner at the end.
- Option to play multiple sessions in one run.

## How to Play
1. Choose the number of rounds you want to play.
2. Enter your choice for each round:
   - `1` for Rock  
   - `2` for Paper  
   - `3` for Scissors
3. The computer will randomly select its choice.
4. View the result for each round and the final scores at the end.

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/moamin21/RockPaperScissorsCPP.git
   cd RockPaperScissorsCPP
   ```
2. Compile the program using a C++ compiler:
   ```bash
   g++ main.cpp -o RockPaperScissors
   ```
3. Run the compiled program:
   ```bash
   ./RockPaperScissors
   ```

> **Note**: This game uses Windows-specific functions like `SetConsoleTextAttribute` for text coloring and `Beep` for sound effects. It may require adjustments to run on other platforms.

## Example Gameplay
```plaintext
Enter the number of rounds: 3

Round 1 - Player vs Computer
Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): 1
Computer chose: Scissors
You win this round!

Round 2 - Player vs Computer
Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): 2
Computer chose: Rock
You win this round!

Round 3 - Player vs Computer
Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): 3
Computer chose: Scissors
This round is a draw!

Game Over!
Final Scores:
Player: 2
Computer: 0
Congratulations! You won the game!
```

## Requirements
- **Windows OS**
- A C++ compiler (e.g., MinGW, Visual Studio)

## Customization
- To modify the game, edit `main.cpp`. For instance:
  - Adjust the number of choices or rules in the game logic.
  - Customize text colors or sound frequencies.

## Contributing
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-name`).
3. Commit your changes (`git commit -m 'Add feature'`).
4. Push the branch (`git push origin feature-name`).
5. Open a pull request.
