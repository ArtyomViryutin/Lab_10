#pragma once
typedef struct list {
	int deg;
	int k;
	struct list *next;
}list;

int input_deg(); // функция ввода степени
int input_k(); // функция ввода коэффициента
list *create(list *head); // функця создания многочлена
list *create_head(); // функция создания первого элемента списка
list * addelem(list *head); // функция добавления узлла в  список
int search_min(list *head); // функция поиска коэффициента при минимальной степени во втором многочлене
void replace(list *head, int min); // функция замены коэффициентов при нечетных степенях в первом многочлене на min
void listprint(list *head); // функция вывода списка
void free_list(list* head); // функция очистки
void check_equal(list *head, int num); // функция проверки на повторение степеней



