#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*

This problem was recently asked by Google:

Design a Tic-Tac-Toe game played between two players on an n x n grid. A move is guaranteed to be valid, and a valid move is one placed on an empty block in the grid. A player who succeeds in placing n of their marks in a horizontal, diagonal, or vertical row wins the game. Once a winning condition is reached, the game ends and no more moves are allowed. Below is an example game which ends in a winning condition:

Given n = 3, assume that player 1 is "X" and player 2 is "O" 
board = TicTacToe(3);

board.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

board.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

board.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

board.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

board.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

board.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

board.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|

Here's a starting point:

class TicTacToe(object):
  def __init__(self, n):
    # Fill this in.

  def move(self, row, col, player):
    # Fill this in.

board = TicTacToe(3)
board.move(0, 0, 1)
board.move(0, 2, 2)
board.move(2, 2, 1)
board.move(1, 1, 2)
board.move(2, 0, 1)
board.move(1, 0, 2)
print(board.move(2, 1, 1))

*/

/* credits:- non-naive implementations
	https://www.programcreek.com/2014/05/leetcode-tic-tac-toe-java/ 
	http://buttercola.blogspot.com/2016/06/leetcode-348-design-tic-tac-toe.html
*/

class TicTacToe {
	int *rows, *cols, diag, adiag, n;
public:
	TicTacToe(int n) {
		rows = new int[n];
		cols = new int[n];
		diag = 0;
		adiag = 0;
		this->n = n;
	};

	int move(int row, int col, int player) {
		int val = player == 1 ? 1 : -1;
		rows[row] += val;
		cols[col] += val;

		if (row == col) diag += val;
		if (row + col == n - 1) adiag += val;

		return abs(rows[row]) == n 
			|| abs(cols[col]) == n 
			|| abs(diag) == n 
			|| abs(adiag) == n 
			? player 
			: 0;
	}
};

int main(){
	TicTacToe board(3);
	board.move(0,0,1);
	board.move(0,2,2);
	board.move(2,2,1);
	board.move(1,1,2);
	board.move(2,0,1);
	board.move(1,0,2);
	cout << board.move(2,1,1) << "\n"; // 1
	return 0;
}