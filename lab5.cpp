#define _CRT_SECURE_NO_WARNINGS // не показываем варнинги о небезопасности fopen
#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

int findpos(char* string, char* req) // функция поиска, string - строка, в которой нужно искать, req - то, что нужно искать
{
	int i=0, symcount=0, position=0; // создаем локальные переменные
	int string_len=strlen(string); // находим длину строки, в которой ищем
	int req_len=strlen(req); // находим длину строки, которую ищем
	for (i=0; i<=string_len; i++){ // проходимся по 
		//printf("%c",string[i]);
		if (symcount==req_len) { // проверяем, равно ли количество совпавших символов длине строки, которую ищем
			position=i-req_len; // вычисляем позицию начала строки, которую нашли
			break; // прерываем цикл
		} else {
			position=-1; // если не находим фразу, то на вывод отдаём -1
		}

		if (symcount==0) { // если мы не нашили ещё ни одной буквы, то смотрим
			if (string[i]==req[0]){ // равна ли текущая буква строки первой букве того, что ищем
				symcount++; // если да, то увеличиваем количество найденных символов на 1
			}
		} else { // если мы уже нашли символ(ы)
			if (string[i]==req[symcount]){ // то смотрим, подходит ли текущий символ из строки, в которой ищем, следующему символу из поиска
				symcount++; // если да, то увеличиваем количество найденных символов на 1
			} else {
				symcount=0; // если нет, то обнуляем счётчик найденных символов
			}
		}
	}
	return(position); // возвращаем позицию
}

int main()
{
	int pos=0, i=0, length=0, len=0, bufflen = 16; // создаем переменные, i - для итерации, length - длина строки из файла
	char *str = new char [1]; // выделяем память для строки
	char c; // текущий символ
	FILE *file1; // file1 - файл
	file1=fopen("text.txt","r"); // открываем файл

	if (file1 == NULL) { // если не можем открыть файл
		printf("Can not open the file!");
		return 0;
	}

	while((c=fgetc(file1))!=EOF) { // ищем длину строки в файле, подразумевается, что в файле только одна строка
		length++; // прибавляем к длине строки 1
		if (c=='\n'){ // если вдруг увидем символ переноса строки, то выходим и пишем об этом
			printf("New line character detected, exiting\n");
			fclose(file1); // закрываем файл
			void exit(); // и выходим
		}
	}

	fseek(file1, -(length), SEEK_CUR); // перемещаем курсор в начало файла
	char *string = new char [length+2]; // выделяем память для строки

	if (string == NULL) { // Проверяем, выделилась ли память
		printf ("No free memory!\n");
		return 0;
	}

	while((c=fgetc(file1))!=EOF) { // снова проходимся по файлу и пишем содержимое в переменную
		string[i]=c;
		i++;
	}
	string[length++]= '\0'; // см. 3-ю лабу
	fclose(file1); // закрываем файл
	printf("Search in: ");
	puts(string);
	printf("Search what: ");

	// код из третьей лабы
	char *req = new char [bufflen];
	while ((c = getchar()) != '\n') {
		req[len] = c;
		len++;
		if (len >= bufflen) {
			char *temp = new char [bufflen*2];
			memcpy (temp, req, bufflen);
			delete req;
			req = temp;
			bufflen = bufflen*2;
			}
		}
	req[len++]= '\0';
	//

	pos=findpos(string, req);
	printf("Position: %d ",pos);
	if (pos==-1) {
		printf("(not found)");
	}
	printf("\n");
	free(string); // очищаем память
	free(req);
	getchar();
}
