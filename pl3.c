#include<stdio.h>
#include<stdlib.h>

char sqr[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g'};

int checkWin() ;
void drawBoard() ;

int  main() {
	int player = 1, i;
        char choice;
       	char mark[3] = {'x', 'o', 'z'}; //x,o,z

	do {
		drawBoard();
		player = (player % 3 == 0) ? 3 : player % 3;
		
	        char currentMark = mark[player - 1];

		printf("Player %d, enter your choice: ", player);

		char in;
		scanf("%c", &in);

	        if(in >= '1' && in <= 'g') {
		choice = in - '0';
		}

		else if( in >= 'a' && in <= 'g') {
		choice = in - 'a' + 10;
		}
		else {
		printf("Invalid Option!!!!\n");
	        continue ;
		}

         	if (sqr[choice] == in) {
                	sqr[choice] = currentMark;
	}
          	else {
		        printf("Invalid move! spot aready taken!\n");
		continue;
	}

		i = checkWin();
		player++;

	}while (i == -1); // game over
	
	drawBoard();
	if(i == 1){
		printf("==> Player %d wins", (player - 1) % 3 == 0 ? 3 : (player - 1) % 3);
	}
	else {
		printf("==> The game is a Draw");
	}
	return 0;
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
	else if (sqr[1] != '1' &&  sqr[2] != '2' && sqr[3] != '3' && sqr[4] != '4' && sqr[5] != '5' && sqr[6] != '6' && sqr[7] != '7' && sqr[8] != '8' && sqr[9] != '9' && sqr[10] != 'a' && sqr[11] != 'b' && sqr[12] != 'c' && sqr[13] != 'd' && sqr[14] != 'e' && sqr[15] != 'f' && sqr[16] != 'g') 
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



