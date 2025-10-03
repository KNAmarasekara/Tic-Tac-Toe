#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char sqr[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};

int checkWin() ;
void drawBoard() ;
void playerMove();
void aiMove();

int  main() {
        int gameStatus;
        int turn = 1;  // player1 is 1 and player2 is 2 ai is 3
	int currentPlayer;

        srand(time(0));

        do {
                drawBoard();
		currentPlayer = turn;

                if (turn == 1 || turn == 2) {
                        playerMove(turn);
                } else{
                        aiMove();
                }

                gameStatus = checkWin();
                turn = (turn % 3) + 1;

        }while (gameStatus == -1);

        drawBoard();

        if (gameStatus == 1) {
		const char* winner = (currentPlayer == 1)? "Player 1 (x)": (currentPlayer == 2) ? "Player 2 (o)" : "Computer (z)";
                printf("==>\a %s wins!\n", winner);
        } else {
                printf("==> \a It's a Draw\n");
        }
        return 0;
}

void playerMove(int player) {
        int choice;
        char mark = (player == 1) ? 'x': 'o';

	while(1){
		printf("Player %d (%c), enter your choice(1-16): ", player, mark);
		scanf("%d", &choice);

		if(choice >= 1 && choice <= 16 && sqr[choice] != 'x' && sqr[choice] != 'o') {
			sqr[choice] = mark;
		break;

	      } else {
		     printf("Invalid move! Try again.\n");
	      } 
        }
}

void aiMove() {
        int choice;
        char mark = 'z';

        do{
                choice = rand() % 16 + 1;
        } while (sqr[choice] == 'x' || sqr[choice] == 'o' || sqr[choice] == 'z');

        printf("The computer is making a choice.......computer chooses %d\n", choice);
        sqr[choice] = mark;
}


int checkWin() {

	//winning conditions for rows 
	if (sqr[1] == sqr[2] && sqr[2] == sqr[3] && sqr[3] == sqr[4])
		return 1;
	else if (sqr[5] == sqr[6] && sqr[6] == sqr[7] && sqr[7] == sqr[8])
                return 1;
        else if (sqr[9] == sqr[10] && sqr[10] == sqr[11] && sqr[11] == sqr[12])
                return 1;
        else if (sqr[13] == sqr[14] && sqr[14] == sqr[15] && sqr[15] == sqr[16])
                return 1;
        
	//winning conditions for colums
	else if (sqr[1] == sqr[5] && sqr[5] == sqr[9] && sqr[9] == sqr[13])
                return 1;
        else if (sqr[2] == sqr[6] && sqr[6] == sqr[10] && sqr[10] == sqr[14])
                return 1;
        else if (sqr[3] == sqr[7] && sqr[7] == sqr[11] && sqr[11] == sqr[15])
                return 1;
        else if (sqr[4] == sqr[8] && sqr[8] == sqr[12] && sqr[12] == sqr[16])
                return 1;


        // winning conditons for cross
	else if (sqr[1] == sqr[6] && sqr[6] == sqr[11] && sqr[11] == sqr[16])
                return 1;
        else if (sqr[4] == sqr[7] && sqr[7] == sqr[10] && sqr[10] == sqr[13])
                return 1;

	// checking for a draw
	else if (sqr[1] != '1' &&  sqr[2] != '2' && sqr[3] != '3' && sqr[4] != '4' && sqr[5] != '5' && sqr[6] != '6' && sqr[7] != '7' && sqr[8] != '8' && sqr[9] != '9' && sqr[10] != 'A' && sqr[11] != 'B' && sqr[12] != 'C' && sqr[13] != 'D' && sqr[14] != 'E' && sqr[15] != 'F' && sqr[16] != 'G') 
		return 0;     // draw

	else 
		return -1;    // still playing
}


//making the drawboard

void drawBoard() {
	system("clear");
	printf("\n\n\t Tic Tac Toe\n\n");
	printf("Player1 (x) - Player2 (o) - Player3 (z) \n\n\n");
	printf("     |     |     |     \n");
	printf("  %c  |  %c  |  %c  |  %c  \n", sqr[1], sqr[2], sqr[3], sqr[4]);
	printf("_____|_____|_____|_____\n");
        printf("     |     |     |     \n");
        printf("  %c  |  %c  |  %c  |  %c  \n", sqr[5], sqr[6], sqr[7], sqr[8]);
        printf("_____|_____|_____|_____\n");
        printf("     |     |     |     \n");
        printf("  %c  |  %c  |  %c  |  %c  \n", sqr[9], sqr[10], sqr[11], sqr[12]);
        printf("_____|_____|_____|_____\n");
        printf("     |     |     |     \n");
        printf("  %c  |  %c  |  %c  |  %c  \n", sqr[13], sqr[14], sqr[15], sqr[16]);
        printf("     |     |     |     \n");

}



