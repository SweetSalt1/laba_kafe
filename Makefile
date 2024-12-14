CC = gcc
OBJ = main.o menu.o

# Правило по умолчанию
all: main

# Линковка объектных файлов в исполнимый файл
main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

# Правила для компиляции исходных файлов
main.o: main.c menu.h
	$(CC) $(CFLAGS) -c main.c

menu.o: menu.c menu.h
	$(CC) $(CFLAGS) -c menu.c

# Правило для очистки файлов
clean:
	rm -f $(OBJ) main

