#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "functions.h"

void newGame() {

	int num;
	FILE *f;

	f = fopen("../source/vocabulary.txt", "r");
	num = checkStringsNum(f);
	fclose(f);

	char **eng;
	char **rus;
	eng = (char**)malloc(num * sizeof(char*));
	for (int i = 0; i < num; i++) {
		eng[i] = (char*)malloc(20 * sizeof(char));
	}
	rus = (char**)malloc(num * sizeof(char*));
	for (int i = 0; i < num; i++) {
		rus[i] = (char*)malloc(20 * sizeof(char));
	}
	
	f = fopen("../source/vocabulary.txt", "r");
	wordsMass(f, eng, rus, num);
	fclose(f);

	for (int i = 0; i < num; i++) {
		printf("%s %s\n", eng[i], rus[i]);
	}
	
	return;

}