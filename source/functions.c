#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int mainMenu() {
	
	setlocale(LC_ALL, "Rus");
	
	int opt;
	printf("\n**************************************\n1. Новая игра\n2. Текущий прогресс\n3. Выход\n\nВыберите действие: ");
	scanf("%d", &opt);

	return opt;

}

int newGameMenu() {

	setlocale(LC_ALL, "Rus");

	int opt;
	printf("\n**************************************\n1. Изучение новых слов\n2. Повторенее изученного\n3. Выход в главное меню\n\nВыберите действие: ");
	scanf("%d", &opt);

	return opt;

}

int checkStringsNum(FILE *f) {

	char ch;
	int num = 0;

	while (!feof(f)) {
		ch = getc(f);
		if (ch == '\n') {
			num++;
		}
	}

	return num;

}

void wordsMass(FILE *f, char **eng, char **rus, int num) {
	
	char ch;
	for (int i = 0; i < 3; i++) {
		ch = getc(f);
	}

	int symb;

	for (int i = 0; i < num; i++) {

		symb = 0;
		ch = getc(f);
		while (ch != '.' && (ch != '\0')) {
			eng[i][symb] = ch;
			symb++;
			ch = getc(f);
		}
		eng[i][symb] = '\0';

		symb = 0;
		ch = getc(f);
		while ((ch != '\n') && (ch != '\0')) {
			rus[i][symb] = ch;
			symb++;
			ch = getc(f);
		}
		rus[i][symb] = '\0';

	}

	return;

}