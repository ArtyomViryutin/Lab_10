#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "Header.h"
#include <stdlib.h>
#include <malloc.h>

void check_equal(list *head, int num) {

	int k = 0, num1;

	num1 = num;

	struct list *p;

	p = head;

	do {

		if (num1 == p->deg)
			k++;

		p = p->next; // переход к следующему узлу


	} while (p != NULL);

	if (k > 1) {

		printf("Ошибка.Вы ввели одну и ту же степень 2 раза.\n"); // выход из программы при введении одинаковых степеней

		system("pause");

		exit(0);

	}

}

int input_k() { //функция ввода коэффициента и проверки на корректность ввода

	double k1; // переменная для проверки ввода

	int k; // переменная ввода

	printf("Введите коэффициент: ");

	if (!scanf("%lf", &k1) || k1 == 0) { printf("Ошибка.Коэффициент должен быть целым числом не равным нулю.\nПопробуйте еще раз.\n");   while (getchar() != '\n'); return 0; }

	if (getchar() != '\n') { printf("Ошибка.Коэффициент должен быть целым числом не равным нулю.\nПопробуйте еще раз.\n"); while (getchar() != '\n'); return 0; }

	k = k1;

	if (k != k1) { printf("Ошибка.Коэффициент должен быть целым числом .\nПопробуйте еще раз.\n"); return 0; }

	return k;
}


int input_deg() { // функция ввода степени и проверки на корректность ввода

	double deg1; // переменная для проверки ввода

	int deg; // переменная ввода

	printf("Введите степень: ");

	if (!scanf("%lf", &deg1) || deg1 < 0) { printf("Ошибка.Степень должна быть целым положительным числом.\nПопробуйте еще раз.\n");  while (getchar() != '\n'); return -1; }

	if (getchar() != '\n') { printf("Ошибка.Степень должна быть целым числом.\nПопробуйте еще раз.\n"); while (getchar() != '\n'); return -1; }

	deg = deg1;

	if (deg != deg1) { printf("Ошибка.Степень должна быть целым числом.\nПопробуйте еще раз.\n"); return -1; }

	return deg;
}


list *create_head() { 

	int deg = -1;
	int k = 0;

	list *head = (list*)malloc(sizeof(list)); // выделение памяти

	while (deg == -1) // цикл ввода степени
		deg = input_deg();

	head->deg = deg;

	while (k == 0) // цикл ввода коэффициента
		k = input_k();

	head->k = k;

	head->next = NULL;

	return (head);

}

list * addelem(list *head) 
{
	int deg = -1;

	int k = 0;

	struct list *temp, *p;

	temp = (struct list*)malloc(sizeof(list));

	p = head->next; // сохранение указателя на следующий узел

	head->next = temp; // предыдущий узел указывает на создаваемый

	while (deg == -1)

		deg = input_deg();

	temp->deg = deg;

	while (k == 0)

		k = input_k();

	temp->k = k;

	temp->next = NULL; // созданный узел указывает на следующий элемент

	return(temp);
}


void listprint(list *head)
{
	struct list *p;

	p = head;

	do {



		if (p->deg == 0) // вывод элемента многочлена со степенью 0 без x
			printf("%d", p->k);

		else printf("%dx^%d", p->k, p->deg); // вывод элементов многочлена

		p = p->next; // переход к следующему узлу

		if (p != 0)
			printf(" + ");

	} while (p != NULL); 

	printf("\n");

}

int search_min(list *head) {

	int min, mind, n = 1;

	struct list *p;

	p = head;

	do {

		if (n == 1) { // присваивание переменным значения степени и коэффициента в первом узле списка
			min = p->k;
			mind = p->deg;
			n++;
		}

		else { // поиск минимального

			if (mind > p->deg)
			{
				min = p->k;
				mind = p->deg;
			}
		}

		p = p->next; // переход к следующему узлу

	} while (p != NULL);

	return min;
}


void replace(list *head, int min) {

	struct list *p;

	p = head;

	do {

		if (p->k % 2 == 1 || p->k % 2 == -1) // проверка на четность степеней первого многочлена
			p->k = min;

		p = p->next; // переход к следующему узлу

	} while (p != NULL);

	printf("\n");

}

list *create(list *head)
{

	list *temp = NULL;

	int i = 1;

	char a;

	head = create_head();

	while (i != 0) {

		printf("-----------------------------------------------------\n");

		printf("Вы хотите продолжить?(y/n): ");

		if (!scanf("%c", &a)) {

		}

		while (getchar() != '\n');

		switch (a) { // оператор выбора продолжения или окончания ввода одночленов

		case 'y':

			if (i == 1) // при первой итерации функция добавления принимает указатель на первый элемент списка
			{
				temp = addelem(head);
				check_equal(head, temp->deg);
			}

			if (i != 1)
			{
				temp = addelem(temp); // при последующих итерациях функция добавления принимает указатель на последующие узлы списка
				check_equal(head, temp->deg);
			}
			if(i==1) // переменная условия первой итерации
				i++;

			break;

		case 'n':

			i = 0; // выход из оператора выхода

			break;


		default:

			printf("Некорректный ввод.\n"); 

			break;

		}
	}
	return head;
}

void free_list(list* head) {
	list* p;
	while (head != NULL) {
		p = head;
		head = head->next;
		free(p);
	}
}
