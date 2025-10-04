#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char checkWin1();
void drawBoard1();
void playerMove1();
void aiMove1();

int checkWin2();
void drawBoard2();

void playerOne();
void playerTwo();
void playerThree();

void drawBoard3();
int checkWin3();
void playerMove3();
void aiMove3();

int sq[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};                                           //array for single player and dual player
char sqr[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};      //array for three player

//The main body of the game
int main() {
	int num;
	printf("\n\n\n     TIC TAC TOE \n\n\n");
	printf("   1.Player vs Computer \n");
	printf("   2.Player vs Player \n");
	printf("   3.Player vs Player vs Computer \n");
	printf("\n   Enter the number of the game of your choice(or any other number to exit): ");
	scanf("%d", &num);

	if(num == 1)
		playerOne();
	else if(num == 2)
		playerTwo();
	else if(num == 3)
		playerThree();
	
	else
		printf("You exited the game.\n");

	return 0;

}

//body of player vs computer
void playerOne() {
        int gameStatus;
        int turn = 1;  // player is 1 and ai is 2

        srand(time(0));

        do {
                drawBoard1();
                if (turn == 1) {
                        playerMove1();
                } else{
                        aiMove1();
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

//body of player vs player
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



//body of player vs player vs computer
void  playerThree() {
        int gameStatus;
        int turn = 1;  // player1 is 1 and player2 is 2 ai is 3
        int currentPlayer;

        srand(time(0));

        do {
                drawBoard3();
                currentPlayer = turn;

                if (turn == 1 || turn == 2) {
                        playerMove3(turn);
                } else{
                        aiMove3();
                }

                gameStatus = checkWin3();
                turn = (turn % 3) + 1;

        }while (gameStatus == -1);

        drawBoard3();

        if (gameStatus == 1) {
                const char* winner = (currentPlayer == 1)? "Player 1 (x)": (currentPlayer == 2) ? "Player 2 (o)" : "Computer (z)";
                printf("==>\a %s wins!\n", winner);
        } else {
                printf("==> \a It's a Draw\n");
        }
    
}



                                                              
int checkWin2() {                                   //checking for a win in dual player
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



char checkWin1() {                                       //checking for a win in single player

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

int checkWin3() {                                         //checking for a win in multiplayer

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



void playerMove1() {            //player move for single player
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
                playerMove1(); // retry

        }
}

void playerMove3(int player) {         //player move for multiplayer
        int choice;
        char mark = (player == 1) ? 'x': 'o';

        while(1){
                printf("\nPlayer %d (%c), enter your choice(1-16): ", player, mark);
                scanf("%d", &choice);

                if(choice >= 1 && choice <= 16 && sqr[choice] != 'x' && sqr[choice] != 'o') {
                        sqr[choice] = mark;
                break;

              } else {
                     printf("Invalid move! Try again.\n");
              }
        }
}


void aiMove1() {                     //AI move for single player
        int choice;
        char mark = 'o';

        do{
                choice = rand() % 9 + 1;
        } while (sq[choice] == 'x' || sq[choice] == 'o');

        printf("The computer is making a choice.......computer chooses %d\n", choice);
        sq[choice] = mark;
}


void aiMove3() {                    //AI move for multiplayer
        int choice;
        char mark = 'z';

        do{
                choice = rand() % 16 + 1;
        } while (sqr[choice] == 'x' || sqr[choice] == 'o' || sqr[choice] == 'z');

        printf("The computer is making a choice.......computer chooses %d\n", choice);
        sqr[choice] = mark;
}




void drawBoard1() {                                     //drawboard for single player 3x3
        system("clear");
        printf("\n\n\t Tic Tac Toe \n\n");
        printf("Player1 (x) - Computer (o) \n\n\n");
        printf("___________________\n");
        printf("|     |     |     |\n");
        printf("|  %c  |  %c  |  %c  |\n", sq[1],sq[2],sq[3]);
        printf("|_____|_____|_____|\n");
        printf("|     |     |     |\n");
        printf("|  %c  |  %c  |  %c  |\n", sq[4],sq[5],sq[6]);
        printf("|_____|_____|_____|\n");
        printf("|     |     |     |\n");
        printf("|  %c  |  %c  |  %c  |\n", sq[7],sq[8],sq[9]);
        printf("|_____|_____|_____|\n");


}

void drawBoard2() {                                     //drawboard for dual player 3x3
        system("clear");
        printf("\n\n\t Tic Tac Toe \n\n");
        printf("Player1 (x) - Player2 (o) \n\n\n");
	printf("___________________\n");
        printf("|     |     |     |\n");
        printf("|  %c  |  %c  |  %c  |\n", sq[1],sq[2],sq[3]);
        printf("|_____|_____|_____|\n");
        printf("|     |     |     |\n");
        printf("|  %c  |  %c  |  %c  |\n", sq[4],sq[5],sq[6]);
        printf("|_____|_____|_____|\n");
        printf("|     |     |     |\n");
        printf("|  %c  |  %c  |  %c  |\n", sq[7],sq[8],sq[9]);
        printf("|_____|_____|_____|\n");

}


void drawBoard3() {                                     //drawboard for multiplayer 4x4 
        system("clear");
        printf("\n\n\t Tic Tac Toe\n\n");
        printf("Player1 (x) - Player2 (o) - Computer (z) \n\n\n");
        printf("Please enter numbers between A-G as A -> 10  B -> 11  c -> 12.....\n\n\n\n\n");
	printf("_________________________\n");
        printf("|     |     |     |     |\n");
        printf("|  %c  |  %c  |  %c  |  %c  |\n", sqr[1], sqr[2], sqr[3], sqr[4]);
        printf("|_____|_____|_____|_____|\n");
        printf("|     |     |     |     |\n");
        printf("|  %c  |  %c  |  %c  |  %c  |\n", sqr[5], sqr[6], sqr[7], sqr[8]);
        printf("|_____|_____|_____|_____|\n");
        printf("|     |     |     |     |\n");
        printf("|  %c  |  %c  |  %c  |  %c  |\n", sqr[9], sqr[10], sqr[11], sqr[12]);
        printf("|_____|_____|_____|_____|\n");
        printf("|     |     |     |     |\n");
        printf("|  %c  |  %c  |  %c  |  %c  |\n", sqr[13], sqr[14], sqr[15], sqr[16]);
        printf("|_____|_____|_____|_____|\n");

}

	
  







