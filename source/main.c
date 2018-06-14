#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "functions.h"

int main(int argc, char *argv[]) {

	setlocale(LC_ALL, "Rus");

	int opt;
	int num;
	FILE *f;

	f = fopen("../source/vocabulary.txt", "r");

	while (1) {
		opt = mainMenu();
		switch (opt) {
			case 1:
				opt = newGameMenu();
				switch (opt) {
				case 1:
					printf("�������� ����� ����\n");
					num = checkWordsNum(f);
					printf("���������� ���� � �����: %d\n", num);
					break;
				case 2:
					printf("���������� ����������\n");
					break;
				case 3:
					break;
				default:
					printf("������� ������ �����������! ����� � ������� ����\n");
					break;
				}
				break;
			case 2:
				printf("������� ��������\n");
				break;
			case 3:
				fclose(f);
				system("PAUSE");
				return 0;
				break;
			default:
				printf("������� ������ �����������!\n");
		}
	}

}