# Memory Game README


Hi there and Welcome to the Memory Game! This is a simple command-line-based memory game written in C++. The goal of the game is to match pairs of numbers within a specified array size.

## Setup
1. **Clone the Repository:**
```bash
git clone <repository_url>
cd MemoryGame
```
2. **Compile the Code:**
```bash
g++ -o MemoryGame MemoryGame.cpp
```
3. **Run the Game:**
```
./MemoryGame
```

## Game Rules
*You will be prompted to enter the size of the array (between 6 and 20). This determines the number of pairs in the game.
*The array will be initialized with numbers, and each number will appear twice.
*You start with all cards facing down.
*On each turn, you input two indices to flip the corresponding cards.
*If the numbers on the flipped cards match, they remain face up. Otherwise, they are turned face down.
*The game continues until all pairs are matched
## How to Play
-Enter the size of the array when prompted.
-Flip cards by entering the indices of the cards you want to reveal.
-If the numbers match, the cards stay face up; otherwise, they are turned face down.
-Continue until all pairs are matched.

## Example Interaction 
```C++
Welcome to the Memory Game!
Enter the size of an array (6-20): 10
Here is the array: ? ? ? ? ? ? ? ? ? ?
Enter the index to show: 1
The card at index 1 is: 5
Enter the second index to show: 7
The card at index 7 is: 2
The cards do not match. Try again!
Press Enter to continue...
...
Game over! All pairs matched in 8 moves.
```

## Thank You For Your Attention And See You Space Cowboy
![](https://media.tenor.com/RF9EdpqI_qIAAAAC/see-you-space-cowboy-cowboy-bebop.gif)