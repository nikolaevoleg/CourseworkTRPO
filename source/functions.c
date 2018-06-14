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

int checkWordsNum(FILE *f) {
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