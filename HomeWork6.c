#include "HomeWork6.h"
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


// Задание 1. Реализовать функцию перевода чисел из десятичной системы в двоичную, используя стэк.
void solution1()
{
	
}

typedef int T;
typedef struct Node
{
	T data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;
//Создане нового узла
Node* getFreeNode(T	value, Node *parent)
{
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}

// Вставка узла
void insert(Node **head, int value) 
{ 
	Node *tmp = NULL;
	if (*head == NULL) 
	{ *head = getFreeNode(value, NULL);
		return; 
	}
	tmp = *head;
	while (tmp) 
	{ 
		if (value> tmp->data) 
		{ 
			if (tmp->right) 
			{ 
				tmp = tmp->right; 
				continue; 
			}
			else 
			{
				tmp->right = getFreeNode(value, tmp); 
				return; 
			}
		}
		else if(value<tmp->data)
		{
			if(tmp-> left)
			{
				tmp = tmp-> left;
				continue;
			}
			else 
			{
				tmp->left = getFreeNode(value, tmp);
				return;
			}
		}
		else
		{
			exit(2); //дерево построено неправильно
		}
	}
}

void preOrderTravers(Node* root) 
{
	if (root) 
	{
		printf("%d ", root->data);
		preOrderTravers(root->left);
		preOrderTravers(root->right);
	}
}void inOrderTravers(Node* root) 
{
	if (root)
	{
		inOrderTravers(root->left);
		printf("%d ", root->data);
		inOrderTravers(root->right);
	}
}
//void postOrderTravers(Node* root)
//{
//	if (root) 
//	{
//		postOrderTravers(root->left);
//		postOrderTravers(root->right);
//		printf("%d ", root->data);
//	}
//}
void find(Node* root, int value)
{
	if (root)
	{
		if (root->data == value)
			printf("here.\n");
		else
		{
			find(root->left, value);
			printf("-left");
			find(root->right, value);
			printf("-right");
		}
	}
}

void printTree(Node *root)
{
	if (root)
	{
		printf("%d", root->data);
		if (root->left || root->right)
		{
			printf("(");
			if (root->left)
				printTree(root->left);
			else
				printf("NULL");
			printf(",");
			if (root->right)
				printTree(root->right);
			else
				printf("NULL");
				printf(")");
		}
	}
}

// Задание 6. Реализовать очередь.
void solution2()
{
	printf("Solution 2.\n");
	int A[10];
	Node *Tree = NULL;
	for (int x = 0; x < 10; x++)
	{
		A[x] = rand() % 50;
	}
	printf("Start Array:\n");
	for (int y = 0; y < 10; y++)
	{
		printf("%4d", A[y]);
	}
	printf("\nTree:\n");
	for (int i = 0; i <= 10; i++)
	{
		insert(&Tree, A[i]);
	}
	printTree(Tree);
	printf("\nPreOrderTravers:\n");
	preOrderTravers(Tree);
	printf("\nInOrderTravers:\n");
	inOrderTravers(Tree);
	/*printf("\nPostOrderTravers:\n");
	PostOrderTravers(Tree);*/	printf("\n");
	printf("Which number to find?\n");
	int answ;
	scanf("%d", &answ);
	printf("Result is:\n");
	find(Tree, answ);
	getchar();
}

void menu()
{
	printf("main menu\n1 - task1\n");
	printf("2 - task2\n");
	printf("0 - exit\n");
}