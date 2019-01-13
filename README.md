# Robot-Turtles-Console-Game-with-Cpp-
It is console version of robot turtles game.


Robot Turtles is played on an 8×8 board. There is one turtle (marked with the letter T), which always starts out at the bottom-left field, facing right. The board contains empty squares (marked as .), castles made out of rock (C), and castles made out of ice (I). The diamond is marked with a D. The turtle may move only onto empty squares and the square on which the diamond is located.

- A turtle program contains 4 kinds of instructions, marked by a single letter.
- F The turtle moves one field forward in the direction it is facing. If the turtle faces a castle or the border of the board, a program error occurs.
- R The turtle turns 90 degrees to the right (the turtle will just turn and stay on the same field).
- L The turtle turns 90 degrees to the left (the turtle will just turn and stay on the same field).
- X The turtle fires a laser in the direction it is facing. If the square it is facing contains an ice castle, the ice castle will melt and the square will turn into an empty square. Otherwise, a program error occurs. The turtle will not move or change direction. It is a program error to fire the laser at empty squares, rock castles or outside the board.


## Input
The input consists of 8 lines, which represents the board, with each line representing one row. The turtle will always start out at the bottom-left. There will be exactly 1 diamond. There will be no more than 10 ice castles.

<br/>

### This is sample map and root to diamond.
![aaa](https://user-images.githubusercontent.com/12279132/51086224-12686000-1755-11e9-8ce2-c757105b3ae9.png)
