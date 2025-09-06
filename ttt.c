#include<stdio.h>

char sq = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

int main () {
	int num;

	printf("               MENU               ");
	printf("1.Single player");
	printf("2.Two players");
	printf("3.Three players");

	printf("PLease type the number of your prefered option");
	scanf("%d", &num);


	if ( num >= 0){
		if (num == 1)
			if (sq[1] == sq[2] && sq[2] == sq[3])
			else if (sq[4] == sq[5] && sq[5] == sq[6])
			else if (sq[7] == sq[8] && sq[8] == sq[9])
			else if (sq[1] == sq[5] && sq[5] == sq[9])
			else if (sq[3] == sq[5] && sq[5] == sq[7])
			else if (sq[1] == sq[4] && sq[4] == sq[7])
			else if (sq[2] == sq[5] && sq[5] == sq[8])
			else if (sq[3] == sq[6] && sq[6] == sq[9])
				printf("Player %d wins");



		printf("      |      |      \n")
		scanf("  %s  |  %s  |  %s  \n", sq[1],sq[2],sq[3])
		printf("______|______|______\n")
		printf("      |      |      \n")
                scanf("  %s  |  %s  |  %s  \n", sq[4],sq[5],sq[6])
                printf("______|______|______\n")
		printf("      |      |      \n")
                scanf("  %s  |  %s  |  %s  \n", sq[7],sq[8],sq[9])
                printf("      |      |      \n")
	else {
		printf("Enter again")
		scanf("%s", num)
	}
	        



                

	}


}
