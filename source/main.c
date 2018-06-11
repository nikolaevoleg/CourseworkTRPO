#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "functions.h"

int main(int argc, char *argv[]) {

	int opt;

	setlocale(LC_ALL, "Rus");

	while (1) {
		opt = mainMenu();
		switch (opt) {
			case 1:
				opt = newGameMenu();
				switch (opt) {
				case 1:
					printf("Изучение новых слов\n");
					break;
				case 2:
					printf("Повторение изученного\n");
					break;
				case 3:
					break;
				default:
					printf("Вариант введен некорректно! Выход в главное меню\n");
					break;
				}
				break;
			case 2:
				printf("Текущий прогресс\n");
				break;
			case 3:
				system("PAUSE");
				return 0;
				break;
			default:
				printf("Вариант введен некорректно!\n");
		}
	}


}