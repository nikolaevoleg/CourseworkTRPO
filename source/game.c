#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "functions.h"

void answQue(int fl, char **eng, char **rus, int num) {

	if (num < 4) {
		printf("Not enough words to test!\n\n");
		
		return;
	}

	FILE *f;

	int k;
	int *ws;

	printf("\n*****************************************\n");
	if (fl == 1) {
		printf("How many words do you want to learn (<%d)? ", num + 1);
	}
	else {
		printf("How many words do you want to repeat (<%d)? ", num + 1);
	}

	while (((scanf("%d", &k)) != 1) || (k < 1) || (k > num)) {
		printf("Invalid input format or invalid number entered. Try again: ");
		while(getchar() != '\n');
	}
	ws = (int*)malloc(k * sizeof(int));
	for (int i = 0; i < k; i++) {
		ws[i] = rand() % num;
		for (int j = i - 1; j >= 0; j--) {
			if (ws[i] == ws[j]) {
				ws[i] = rand() % num;
				j = i;
			}
		}
	}

	printf("\n*****************************************\n");

	printf("Read the words:\n\n");
	for (int i = 0; i < k; i++) {
		printf("%s - %s\n", eng[ws[i]], rus[ws[i]]);
	}
	printf("\n");

	if (fl == 1) {
		f = fopen("../source/studied.txt", "a+");
	}

	int var[4];
	int n;
	int answ;
	int sum = 0;

	for (int i = 0; i < k; i++) {
		n = rand() % 4;
		var[n] = ws[i];

		for (int j = 0; j < 4; j++) {
			if (j != n) { 
				var[j] = rand() % num;
				if (j == 0){
					while (var[j] == var[n]){
						var[j] = rand() % num;
					}
				} 
				else {
					for (int z = j - 1; z >= 0; z--) {
						if ((var[j] == var[z]) || (var[j] == var[n])) {
							var[j] = rand() % num;
							z = j;
						}
					}
				}	
			}
		}

		printf("\n*****************************************\n");
		printf("%d out of %d\n\n%s:\n1: %s\n2: %s\n3: %s\n4: %s\n\n", 
			    i + 1, k, eng[ws[i]], rus[var[0]], rus[var[1]], rus[var[2]], rus[var[3]]);
		printf("Select option(1-4): ");

		while (((scanf("%d", &answ)) != 1) || (answ < 1) || (answ > 4)) {
			printf("Invalid input format or invalid number entered. Try again: ");
			while(getchar() != '\n');
		}

		if (answ == n + 1) {
			if (fl == 1) {
				fprintf(f, "%s.%s\n", eng[ws[i]], rus[ws[i]]);
				strcpy(eng[ws[i]], "0");
			}
			sum++;
		}

	}

	if (fl == 1) {
		fclose(f);
		f = fopen("../source/vocabulary.txt", "w");
		for (int i = 0; i < num; i++) {
			if (strcmp(eng[i], "0") != 0 ) {
				fprintf(f, "%s.%s\n", eng[i], rus[i]);
			}
		}
		fclose(f);
	}

	printf("\nCorect answers: %d out of %d\n\n", sum, k);

	free(ws);

	
	return;

}

void newGame(int fl) {

	srand(time(NULL));

	int num;
	
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

	answQue(fl, eng, rus, num);

	for (int i = 0; i < num; i++) {
		free(eng[i]);
	}
	free(eng);

	for (int i = 0; i < num; i++) {
		free(rus[i]);
	}
	free(rus);

	return;

}
