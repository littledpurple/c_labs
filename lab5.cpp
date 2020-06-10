#define _CRT_SECURE_NO_WARNINGS // �� ���������� �������� � �������������� fopen
#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

int findpos(char* string, char* req) // ������� ������, string - ������, � ������� ����� ������, req - ��, ��� ����� ������
{
	int i=0, symcount=0, position=0; // ������� ��������� ����������
	int string_len=strlen(string); // ������� ����� ������, � ������� ����
	int req_len=strlen(req); // ������� ����� ������, ������� ����
	for (i=0; i<=string_len; i++){ // ���������� �� 
		//printf("%c",string[i]);
		if (symcount==req_len) { // ���������, ����� �� ���������� ��������� �������� ����� ������, ������� ����
			position=i-req_len; // ��������� ������� ������ ������, ������� �����
			break; // ��������� ����
		} else {
			position=-1; // ���� �� ������� �����, �� �� ����� ����� -1
		}

		if (symcount==0) { // ���� �� �� ������ ��� �� ����� �����, �� �������
			if (string[i]==req[0]){ // ����� �� ������� ����� ������ ������ ����� ����, ��� ����
				symcount++; // ���� ��, �� ����������� ���������� ��������� �������� �� 1
			}
		} else { // ���� �� ��� ����� ������(�)
			if (string[i]==req[symcount]){ // �� �������, �������� �� ������� ������ �� ������, � ������� ����, ���������� ������� �� ������
				symcount++; // ���� ��, �� ����������� ���������� ��������� �������� �� 1
			} else {
				symcount=0; // ���� ���, �� �������� ������� ��������� ��������
			}
		}
	}
	return(position); // ���������� �������
}

int main()
{
	int pos=0, i=0, length=0, len=0, bufflen = 16; // ������� ����������, i - ��� ��������, length - ����� ������ �� �����
	char *str = new char [1]; // �������� ������ ��� ������
	char c; // ������� ������
	FILE *file1; // file1 - ����
	file1=fopen("text.txt","r"); // ��������� ����

	if (file1 == NULL) { // ���� �� ����� ������� ����
		printf("Can not open the file!");
		return 0;
	}

	while((c=fgetc(file1))!=EOF) { // ���� ����� ������ � �����, ���������������, ��� � ����� ������ ���� ������
		length++; // ���������� � ����� ������ 1
		if (c=='\n'){ // ���� ����� ������ ������ �������� ������, �� ������� � ����� �� ����
			printf("New line character detected, exiting\n");
			fclose(file1); // ��������� ����
			void exit(); // � �������
		}
	}

	fseek(file1, -(length), SEEK_CUR); // ���������� ������ � ������ �����
	char *string = new char [length+2]; // �������� ������ ��� ������

	if (string == NULL) { // ���������, ���������� �� ������
		printf ("No free memory!\n");
		return 0;
	}

	while((c=fgetc(file1))!=EOF) { // ����� ���������� �� ����� � ����� ���������� � ����������
		string[i]=c;
		i++;
	}
	string[length++]= '\0'; // ��. 3-� ����
	fclose(file1); // ��������� ����
	printf("Search in: ");
	puts(string);
	printf("Search what: ");

	// ��� �� ������� ����
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
	free(string); // ������� ������
	free(req);
	getchar();
}
