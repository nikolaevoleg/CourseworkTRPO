#include <stdio.h>
#include <locale.h>

int mainMenu() {
	
	setlocale(LC_ALL, "Rus");
	
	int opt;
	printf("\n**************************************\n1. ����� ����\n2. ������� ��������\n3. �����\n\n�������� ��������: ");
	scanf("%d", &opt);

	return opt;

}