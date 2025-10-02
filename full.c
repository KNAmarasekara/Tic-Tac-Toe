#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char checkWin1();
void drawBoard1();
void playerMove();
void aiMove();
int checkWin2();
void drawBoard2();
void playerMove();
void playerOne();
void playerTwo();



int sq[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


int main() {
	int num;
	printf("\n\n\nTIC TAC TOE \n\n\n");
	printf("\n 1.Player vs Computer \n");
	printf("\n 2.Player vs Player \n");
	printf("\n 3.Player vs Player vs Player \n");
	printf("\nEnter the number of the game of your choice(or any other number to exit): \n");
	scanf("%d", &num);

	if(num == 1)
		playerOne();
	else if(num == 2)
		playerTwo();
	
	else
		printf("Game is over");

	return 0;

}

void playerOne() {
        int gameStatus;
        int turn = 1;  // player is 1 and ai is 2

        srand(time(0));

        do {
                drawBoard1();
                if (turn == 1) {
                        playerMove();
                } else{
                        aiMove();
                }

                gameStatus = checkWin1();
                turn = (turn == 1) ? 2:1;

        }while (gameStatus == -1);

        drawBoard1();

        if (gameStatus == 1) {
                printf("==>\a %s wins!\n", (turn == 2) ? "Player" : "Computer");
        } else {
                printf("==> \a It's a Draw\n");
        }
        
}


void playerTwo() {
        int player = 1, i, choice;
        char mark; // x,o
        do{
                drawBoard2();
                player = (player % 2) ? 1 : 2;
                printf("Player%d, enter the choice: ", player);
                scanf("%d", &choice);
                mark = (player == 1) ? 'x' : 'o';

                if(choice == 1 && sq[1] == '1'){                   //inputing data x o
                        sq[1] = mark;}
                 else if (choice == 2 && sq[2] == '2'){
                        sq[2] = mark;}
                 else if (choice == 3 && sq[3] == '3'){
                        sq[3] = mark;}
                 else if (choice == 4 && sq[4] == '4'){
                        sq[4] = mark;}
                 else if (choice == 5 && sq[5] == '5'){
                        sq[5] = mark;}
                 else if (choice == 6 && sq[6] == '6'){
                        sq[6] = mark;}
                 else if (choice == 7 && sq[7] == '7'){
                        sq[7] = mark;}
                 else if (choice == 8 && sq[8] == '8'){
                        sq[8] = mark;}
                 else if (choice == 9 && sq[9] == '9'){
                        sq[9] = mark;}

                else {
                        printf("Invalid option !!!");
                        player--;
                        getchar();
                }
                i = checkWin2();
                player++;

               } while(i == -1); // game over
        drawBoard2();
        if(i ==1)
                printf("==> \a Player %d wins\n ", --player);
        else
                printf("==> Game draw\n");   
}











//cheking if there is a win
int checkWin2() {
        if(sq[1] == sq[2] && sq[2] == sq[3])
                return 1;
        else if (sq[4] == sq[5] && sq[5] == sq[6])
                return 1;
        else if (sq[7] == sq[8] && sq[8] == sq[9])
                return 1;                            //check rows

        else if (sq[1] == sq[4] && sq[4] == sq[7])
                return 1;
        else if (sq[2] == sq[5] && sq[5] == sq[8])
                return 1;
        else if (sq[3] == sq[6] && sq[6] == sq[9])
                return 1;                           //check columns

        else if (sq[1] == sq[5] && sq[5] == sq[9])
                return 1;
        else if (sq[3] == sq[5] && sq[5] == sq[7])
                return 1;                           //check cross

        else if (sq[1] != '1' && sq[2] != '2' && sq[3] != '3' && sq[4] != '4' && sq[5] != '5' && sq[6] != '6' && sq[7] != '7' && sq[8] != '8' && sq[9] != '9' )
                return 0;                           // draw
        else
                return -1;  	//still playing

	return 0;

 }



char checkWin1() {


int winCondition[8][3]  = {
        {1,2,3}, {4,5,6}, {7,8,9}, {1,4,7}, {2,5,8}, {3,6,9}, {1,5,9}, {3,5,7}
};
 for (int i = 0; i < 8; i++) { // checking for a win
        if (sq[winCondition[i][0]] == sq[winCondition[i][1]] && sq[winCondition[i][1]] == sq[winCondition[i][2]] ) {
             return 1;
        }
        }
        for (int i = 1; i <= 9; i++) {
                if (sq[i] != 'x' && sq[i] != 'o') {
                        return -1; // game is still ongoing

                }
}
        return 0; // draw

}


void playerMove() {
        int choice;
        char mark = 'x';

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1 && sq[1] == '1') {
                sq[1] = mark; }
        else if (choice == 2 && sq[2] == '2') {
                sq[2] = mark; }
        else if (choice == 3 && sq[3] == '3') {
                sq[3] = mark; }
        else if (choice == 4 && sq[4] == '4') {
                sq[4] = mark; }
        else if (choice == 5 && sq[5] == '5') {
                sq[5] =mark; }
        else if (choice == 6 && sq[6] == '6') {
                sq[6] = mark; }
        else if (choice == 7 && sq[7] == '7') {
                sq[7] = mark; }
        else if (choice == 8 && sq[8] == '8') {
                sq[8] = mark; }
        else if (choice == 9 && sq[9] == '9') {
                sq[9] = mark; }

        else {
                printf("Invalid option!!!!");
                getchar(); // waiting for entering
                getchar(); //pause
                playerMove(); // retry

        }
}

void aiMove() {
        int choice;
        char mark = 'o';

        do{
                choice = rand() % 9 + 1;
        } while (sq[choice] == 'x' || sq[choice] == 'o');

        printf("The computer is making a choice.......computer chooses %d\n", choice);
        sq[choice] = mark;
}





//making the drawboard
void drawBoard1() {
        system("clear");
        printf("\n\n\t Tic Tac Toe \n\n");
        printf("Player1 (x) - Computer (o) \n\n\n");
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

void drawBoard2() {
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



	
  







