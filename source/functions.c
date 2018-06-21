#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dotcheck(char ch)
{
    if (ch == '.')
        return true;
    else
        return false;
}

int mainMenu() {

	printf("\n*****************************************\n");

	int opt;
	printf("1. New game\n2. Current progress\n3. Exit\n\nSelect an action: ");
	while (((scanf("%d", &opt)) != 1) || (opt < 1) || (opt > 3)) {
		printf("Invalid input format or invalid number entered. Try again: ");
		while(getchar() != '\n');
	}

	return opt;

}

int newGameMenu() {

	printf("\n*****************************************\n");

	int opt;
	printf("1. Learn new words\n2. Repeat the words\n3. Return to the main menu\n\nSelect an action: ");
	while (((scanf("%d", &opt)) != 1) || (opt < 1) || (opt > 3)) {
		printf("Invalid input format or invalid number entered. Try again: ");
		while(getchar() != '\n');
	}


	return opt;

}

int checkStringsNum(int fl) {

	FILE *f;
	if (fl == 1) {
		f = fopen("../source/vocabulary.txt", "r");
	}
	else {
		f = fopen("../source/studied.txt", "r");
	}

	char ch;
	int num = 0;

	while ((ch = getc(f)) != EOF) {
		if (dotcheck(ch) == true) {
			num++;
		}
	}

	fclose(f);

	return num;

}

void wordsMass(int fl, char **eng, char **rus, int num) {
	
	FILE *f;
	if (fl == 1) {
		f = fopen("../source/vocabulary.txt", "r");
	}
	else {
		f = fopen("../source/studied.txt", "r");
	}

	char ch;
	int symb;

	for (int i = 0; i < num; i++) {

		symb = 0;
		ch = getc(f);
		while (ch != '.' && (!feof(f))) {
			if (symb < 39){
				eng[i][symb] = ch;
				symb++;
			}
			ch = getc(f);
		}
		eng[i][symb] = '\0';

		symb = 0;
		ch = getc(f);
		while ((ch != '\n') && (!feof(f))) {
			if (symb < 39) {
				rus[i][symb] = ch;
				symb++;
			}
			ch = getc(f);
		}
		rus[i][symb] = '\0';

	}

	fclose(f);

	return;

}