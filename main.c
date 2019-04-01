#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include "Header.h"
#include <stdlib.h>	
#include <malloc.h>

void main() {

	setlocale(LC_ALL, "Rus"); // подключение русских букв

	system("chcp 1251");

	system("cls"); // очистка экрана консоли

	list *head1 = NULL, *head2 = NULL; // указатели на первые элементы списков

	int min; // переменная минимального коэффициета при наименьшей степени второго многочлена

	printf("Введите первый многочлен:\n");

	head1 = create(head1); // создание первого списка

	system("cls"); // очистка экрана консоли

	printf("Введите второй многочлен:\n");

	head2 = create(head2); // создание второго списка

	system("cls"); // очистка экрана консоли

	printf("Начальные многочлены:\n");

	listprint(head1); // вывод первого списка до изменений

	listprint(head2); // вывод второго списка

	min = search_min(head2); // поиск коэффициента при минимальной степени во втором многочлене

	replace(head1, min); // замена коэффициентов при нечетных степенях в первом многочлене на min

	printf("Измененные многочлены:\n");

	listprint(head1); // вывод первого списка после изменений

	listprint(head2); // вывод второго списка

	free_list(head1); // очистка первого списка

	free_list(head2); // очистка второго списка

	system("pause");

}
