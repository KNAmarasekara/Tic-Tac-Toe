#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>


char sq[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}

char checkWin();
void drawBoard();

int main() {

	drawboard();
	printf("Enter your choice: ");
	scanf("%d", &choice);

	if (choice == 1 && sq[1] == '1') {
		sq[1] = mark; }
	else if (choice == 2 && sq[2] == '2') {
		sq[2] = mark; }
        else if (choice == 3 && sq[3] == '3') {
                sq[3] mark; }
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
		player--;
		getchar();
	}
}

void drawBoard() {

        




