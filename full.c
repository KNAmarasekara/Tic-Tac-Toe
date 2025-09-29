#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define playerOne

char checkWin1();
void drawBoard1();
void playerMove();
void aiMove();
char checkWin2();
void drawBoard2();
void playerMove();
int num;

int sq[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'} ;



int main() {
	printf("\n\n\nTIC TAC TOE \n\n\n");
	printf("\n 1.Player vs Computer \n");
	printf("\n 2.Player vs Player \n");
	printf("\n 3.Player vs Player vs Player \n");
	printf("\nEnter the number of the game of your choice: \n");
	scanf("%d", &num);

	if (num == 1){
		int playerOne() {
		int player = 1, i, choice;
		char mark;
		do{
			drawBoard1();
		        player = (player % 2) ? 1 : 2;
		        printf("Player%d, enter the choice: ", player);
		        scanf("%d", &choice);
		        mark = (player == 1) ? 'x' : 'o';

			for (i = 1 ; i <= 9; i++)
				if(choice == i && sq[i] == 'i'){
					sq[i] = mark; }
				else {
					printf("Invalid option !!!");
		                 	player--;
			                getchar();
		                }
		      	i = checkWin1();
           		player++;

				} while(i == -1); // game over
                                	drawBoard1();
	                                if(i ==1)
						printf("==> \a Player %d wins\n ", --player);
					else
						printf("==> Game draw\n");
					return 0;
	        }
		int checkWin1() {
			if(sq[1] == sq[2] && sq[2] == sq[3])
				return 1;
			else if (sq[4] == sq[5] && sq[5] == sq[6])
				return 1;
			else if (sq[7] == sq[8] && sq[8] == sq[9])
				return 1;         // check rows
						 
			else if (sq[1] == sq[4] && sq[4] == sq[7])
                                return 1;
			else if (sq[2] == sq[5] && sq[5] == sq[8])
				return 1;
			else if (sq[3] == sq[6] && sq[6] == sq[9])
				return 1;             // check columns

			else if (sq[1] == sq[5] && sq[5] == sq[9])
				return 1;
			else if (sq[3] == sq[5] && sq[5] == sq[7])
				return 1;            // check cross shape

			else if (sq[1] != '1' && sq[2] != '2' && sq[3] != '3' && sq[4] != '4' && sq[5] != '5' && sq[6] != '6' && sq[7] != '7' && sq[8] != '8' && sq[9] != '9' )
				return 0; // draw
			else
				return -1; // still playing

			return 0;
		}

		//making the drawboard1
		void drawBoard1() {
			system("clear");
			printf("\n\n\t Tic Tac Toe \n\n");
			printf("Player1 (x) - Player2 (o) \n\n\n");
			printf("     |     |     \n");
			printf("  %c  |  %c  |  %c  \n", sq[1],sq[2],sq[3]);
          		printf("_____|_____|_____\n");
                        printf("     |     |     \n");
                        printf("  %c  |  %c  |  %c  \n", sq[4],sq[5],sq[6]);
                        printf("_____|_____|_____\n");
                        printf("     |     |     \n");
                        printf("  %c  |  %c  |  %c  \n", sq[7],sq[8],sq[9]);
                        printf("     |     |     \n");

               }

		return 0;
	}
	return 0;
}



	
  







