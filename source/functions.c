#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int mainMenu() {
	
	setlocale(LC_ALL, "Rus");
	
	int opt;
	printf("\n**************************************\n1. ����� ����\n2. ������� ��������\n3. �����\n\n�������� ��������: ");
	scanf("%d", &opt);

	return opt;

}

int newGameMenu() {

	setlocale(LC_ALL, "Rus");

	int opt;
	printf("\n**************************************\n1. �������� ����� ����\n2. ���������� ����������\n3. ����� � ������� ����\n\n�������� ��������: ");
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