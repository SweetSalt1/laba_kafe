#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

extern Dish dish[100];
extern int n;

int main(){
	const char *filename = "menu";

	if(load_database(filename, dish, &n) != 0){
		printf("Ошибка загрузки базы данных.\n");
		return 1;
	}

	int index;
	char name[100];
	char description[100];
	float price, weight;
	float minPrice, maxPrice;
	float minWeight, maxWeight;
	int choose;

	printf("Выберите действие: \n1) Показать меню. \n2) Найти блюдо в меню. \n3) Добавить новое блюдо. \n4) Удалить блюдо из меню. \n5) Отредактировать блюдо.\n");
	scanf("%i", &choose);
	printf("\n");

	switch(choose){
	case 1:
		printf("Меню.\n");
		Print();
		break;
	case 2:
		printf("Введите минимальную и максимальную цену: ");
		scanf("%f %f", &minPrice, &maxPrice);
		printf("Введите минимальный и максимальный вес: ");
		scanf("%f %f", &minWeight, &maxWeight);

		Search(minPrice, maxPrice, minWeight, maxWeight);
		break;
	case 3:
		printf("Введите название: ");
		scanf("%99s", name);
		printf("Введите цену: ");
		scanf("%f", &price);
		printf("Введите вес: ");
		scanf("%f", &weight);
		printf("Введите описание: ");
		scanf("%99s", description);

		Add(name, price, weight, description);
		break;
	case 4:
		printf("Введите индекс для удаления: ");
		scanf("%d", &index);
		Remuve(index - 1);
		break;
	case 5:
		printf("Введите индекс для редактирования: ");
		scanf("%d", &index);

		if(index < 1 || index > n){
			printf("Неверный индекс. Введите индекс от 1 до %d.\n", n);
			break;
		}

		printf("Введите новое название: ");
		scanf("%99s", name);
		getchar();

		printf("Введите новую цену: ");
		scanf("%f", &price);
		printf("Введите новый вес: ");
		scanf("%f", &weight);
		printf("Введите новое описание: ");
		scanf("%99s", description);
		getchar();

		Edit(index - 1, name, price, weight, description);
			break;
	default:
		printf("Выберите от 1 до 5!\n");
		break;
	}
	return 0;
}
