#include <stdlib.h>
#include <stdio.h>
#include "game.h"
#include "functions.h"

int main(int argc, char *argv[]) {

	int opt;

	while (1) {
		opt = mainMenu();
		switch (opt) {
			case 1:
				opt = newGameMenu();
				switch (opt) {
				case 1:
					newGame(1);
					break;
				case 2:
					newGame(2);
					break;
				case 3:
					break;
				default:
					printf("\n*****************************************\n");
					printf("You have entered invalid data. Please try again.\n");
					break;
				}
				break;
			case 2:
				printf("\n*****************************************\n");
				printf("Current progress.\nLearned %d words out of %d\n\n", checkStringsNum(2), checkStringsNum(1)+ checkStringsNum(2));
				break;
			case 3:
				return 0;
				break;
			default:
				printf("You have entered invalid data. Please try again.\n");
		}
	}

}