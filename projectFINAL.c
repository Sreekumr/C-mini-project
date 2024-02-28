#include <stdio.h>
int i;
char bd[3][3] = {{'1', '2', '3'},
                {'4', '5', '6'},
                {'7', '8', '9'}};

void Board() {
    printf("\n");
    printf("=============\n");
     
    for ( i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", bd[i][0], bd[i][1], bd[i][2]);
    
        printf("-------------\n");
    }
}

int checkWin( char player) {
    // Check rows and columns
    for ( i = 0; i < 3; i++) {
        if ((bd[i][0] == player && bd[i][1] == player && bd[i][2] == player) ||
            (bd[0][i] == player && bd[1][i] == player && bd[2][i] == player)) {
            return 1; // Player won
        }
    }

    // Check diagonals
    if ((bd[0][0] == player && bd[1][1] == player && bd[2][2] == player) ||
        (bd[0][2] == player && bd[1][1] == player && bd[2][0] == player)) {
        return 1; // Player won
    }
   
    
    return 0; // No winner yet
}


int main() {
    

    int playerTurn = 1; // Player 1 starts. 

    int choice,move;

    printf("X-0-X Game\n");

    for ( move = 0; move < 9; move++)
	 {
        Board();

        printf("Player %d, enter your move (1-9): ", playerTurn);
        scanf("%d", &choice);

        // Check if the chosen cell is valid
        if (choice < 1 || choice > 9 || bd[(choice - 1) / 3][(choice - 1) % 3] == 'X' || bd[(choice - 1) / 3][(choice - 1) % 3] == 'O')
		 {
            printf("Invalid move. Try again.\n");
            move--; // Repeat the same move
            continue;
        }

        // Make the move
        bd[(choice - 1) / 3][(choice - 1) % 3] = (playerTurn == 1) ? 'X' : 'O';

        // Check if the current player has won
        if (checkWin((playerTurn == 1) ? 'X' : 'O'))
		 {
            Board(bd);
            printf("Player %d wins!\n", playerTurn);
            break;
        }

        // Switch to the other player
        playerTurn = (playerTurn == 1) ? 2 : 1;
    }

    return 0;
}


