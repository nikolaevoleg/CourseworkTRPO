#include <stdio.h>
#include <locale.h>

int mainMenu() {
	
	setlocale(LC_ALL, "Rus");
	
	int opt;
	printf("\n**************************************\n1. Новая игра\n2. Текущий прогресс\n3. Выход\n\nВыберите действие: ");
	scanf("%d", &opt);

	return opt;

}