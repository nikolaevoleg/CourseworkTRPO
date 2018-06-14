#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include "functions.h"

void newGame(int fl) {

	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int num;
	FILE *f;

	f = fopen("../source/studied.txt", "a+");
	num = checkStringsNum(fl);

	char **eng;
	char **rus;
	eng = (char**)malloc(num * sizeof(char*));
	for (int i = 0; i < num; i++) {
		eng[i] = (char*)malloc(40 * sizeof(char));
	}
	rus = (char**)malloc(num * sizeof(char*));
	for (int i = 0; i < num; i++) {
		rus[i] = (char*)malloc(40 * sizeof(char));
	}

	wordsMass(fl, eng, rus, num);
	
	system("cls");

	int k;
	int *ws;
	printf("������� ���� ������ ������� (<%d)? ", num+1);
	scanf("%d", &k);
	while ((k < 0) || (k > num)) {
		printf("������� ��� ���: ");
		scanf("%d", &k);
	}
	ws = (int*)malloc(k * sizeof(int));
	for (int i = 0; i < k; i++) {
		ws[i] = rand() % num;
		for (int j = i-1; j >= 0; j--) {
			if (ws[i] == ws[j]) {
				ws[i] = rand() % num;
				j = i;
			}
		}
	}

	system("cls");

	printf("������������ �� �������:\n\n");
	for (int i = 0; i < k; i++) {
		printf("%s - %s\n", eng[ws[i]], rus[ws[i]]);
	}
	printf("\n");
	system("PAUSE");

	int var[4];
	int n;
	int answ;
	int sum = 0;
	for (int i = 0; i < k; i++) {
		n = rand() % 4;
		for (int j = 0; j < 4; j++) {
			var[j] = rand() % num;
			for (int z = j-1; z >= 4; z--) {
				if ((var[j] == var[z]) || (var[j] == ws[i])) {
					var[j] = rand() % num;
					z = j;
				}
			}
		}
		var[n] = ws[i];
		system("cls");
		printf("%d �� %d\n\n%s:\n1: %s\n2: %s\n3: %s\n4: %s\n\n", i+1, k, eng[ws[i]], rus[var[0]], rus[var[1]], rus[var[2]], rus[var[3]]);
		printf("�������� �������(1-4): ");
		scanf("%d", &answ);
		if (answ == n+1) {
			fprintf(f, "%s.%s\n", eng[ws[i]], rus[ws[i]]);
			eng[ws[i]] = "0";
			sum++;
		}
	}
	fclose(f);

	f = fopen("../source/vocabulary.txt", "w");
	for (int i = 0; i < num; i++) {
		if (eng[i] != "0") {
			fprintf(f, "%s.%s\n", eng[i], rus[i]);
		}
	}
	fprintf(f, "\0");
	fclose(f);

	printf("\n������ �������: %d �� %d\n\n", sum, k);

	for (int i = 0; i < num; i++) {
		free(eng[i]);
	}
	free(eng);

	for (int i = 0; i < num; i++) {
		free(rus[i]);
	}
	free(rus);

	system("PAUSE");

	return;

}