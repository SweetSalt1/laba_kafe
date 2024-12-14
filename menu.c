#include <stdio.h>
#include "menu.h"

Dish dish[100]={0};
int n = 0;

int load_database(const char *filename, Dish dishArray[100], int *n){
	FILE *file = fopen(filename, "r");
	if(!file){
		printf("Нет файла %s.\n", filename);
		return -1;
	}
	*n = 0;
	while(fscanf(file, "%99[^|]|%f|%f|%99[^\n]\n", dishArray[*n].name, &dishArray[*n].price, &dishArray[*n].weight, dishArray[*n].description) == 4){
		(*n)++;
		if(*n >= 100){
			printf("Слишком много блюд (100).\n");
			break;
		}
	}
	fclose(file);
	return 0;
}

int Save(const char *filename, Dish dishArray[100], int n){
	FILE *file = fopen(filename, "w");
	if (!file){
		printf("Не удалось открыть файл %s для записи.\n", filename);
		return -1;
	}

	for(int i = 0; i < n; i++){
		fprintf(file, "%s|%f|%f|%s\n", dishArray[i].name, dishArray[i].price, dishArray[i].weight, dishArray[i].description);
	}

    fclose(file);
    return 0;
}


void copyStr(char *suda, const char *otsuda) {
	int i = 0;
	while(otsuda[i] != '\0' && i < 149){
		suda[i] = otsuda[i];
		i++;
	}
	suda[i] = '\0';
}

void Init(){
	n = 0;
}

void Print() {
	printf("Меню:\n");
	for (int i = 0; i < n; i++) {
		 printf("%d. Название: %s | Цена: %f | Вес: %f | Описание: %s\n", i + 1, dish[i].name, dish[i].price, dish[i].weight, dish[i].description);
	}
}

int Add(char *name, float price, float weight, char *description) {
	if(n >= 100){
		printf("Блюдо не добавлено.\n");
		return -1;
	}
	copyStr(dish[n].name, name);
	dish[n].price = price;
	dish[n].weight = weight;
	copyStr(dish[n].description, description);
	n++;

	if(Save("menu", dish, n) != 0){
		printf("Ошибка при сохранении данных в файл.\n");
		return -1;
	}
	printf("Блюдо добавлено.\n");
	return 0;
}

int Edit(int index, char *name, float price, float weight, char *description){
	if(index < 0 || index >= n){
		printf("Неверный индекс.\n");
		return -1;
	}
	copyStr(dish[index].name, name);
	dish[index].price = price;
	dish[index].weight = weight;
	copyStr(dish[index].description, description);

	if(Save("menu", dish, n) != 0){
		printf("Ошибка при сохранении изменений в файл.\n");
		return -1;
	}
	printf("Блюдо отредактированною\n");
	return 0;
}


int Remuve(int index){
	if(index < 0 || index >= n){
		printf("Неверный индекс.\n");
		return -1;
	}

	for(int i = index; i < n - 1; i++){
		dish[i] = dish[i + 1];
	}

	n--;
	if(Save("menu", dish, n) != 0){
		printf("Ошибка при сохранении изменений в файл.\n");
		return -1;
	}

	printf("Блюдо успешно удалено.\n");
	return 0;
}


void Search(float minPrice, float maxPrice, float minWeight, float maxWeight){
	printf("Результаты поиска:\n");
	for (int i = 0; i < n; i++){
		if (dish[i].price >= minPrice && dish[i].price <= maxPrice && dish[i].weight >= minWeight && dish[i].weight <= maxWeight){
			printf("%d. Название: %s | Цена: %f | Вес: %f | Описание: %s\n", i + 1, dish[i].name, dish[i].price, dish[i].weight, dish[i].description);
        }
    }
}
