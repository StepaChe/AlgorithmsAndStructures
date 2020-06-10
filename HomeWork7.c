#include "HomeWork7.h"
#include <stdio.h>
#include <malloc.h>

// Чередниченко Степан Максимович

void solution1();
void solution2();
void menu();

int main()
{
	int sel = 0;

	do
	{
		menu();
		scanf("%i", &sel);
		switch (sel)
		{
		case 1:
			solution1();
			break;
		case 2:
			solution2();
			break;
		case 0:
			printf("Goodbye!");
			break;
		default:
			printf("Wrong selected.\n");
		}
	} while (sel != 0);

	return 0;
}


// Задание 1. 
void solution1()
{
	printf("Solution 1.\n");

	getchar();
}

// Задание 2. .
void solution2()
{
	printf("Solution 2.\n");
	
	getchar();
}

void menu()
{
	printf("main menu\n1 - task1\n");
	printf("2 - task2\n");
	printf("0 - exit\n");
}