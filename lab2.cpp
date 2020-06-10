#include <stdio.h>
 
int main(void){
    int i, zeronum = 0, j = 0, k = 0; // i - ������� ��� ������, zeronum - ���������� ������ ������ �����, j - ������ ������� �� ������, k - ������� ��� ������� �� ������
    int a[] = { 1, 2, 3, 0, 1, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 1 }; // ����������� ������
    int n   = sizeof(a)/sizeof(a[0]); // ������� ����� ���������� �������
    // printf("The length of source is %d\n", n);
	printf("Source: ");
	for (i = 0; i < n; i++) {
		printf("%d ",a[i]);
		if (i != n-1) { // ���������, �� ��������� �� ��� ����� � ����������� �������
			if (a[i] !=0){
				j++; // ���� ����� � �������� ������� �� ����� ����, �� ���������� 1 � ����� ������� �� ������
			} else {
				zeronum++; // ���� ������� ����� ����� ����, �� ���������� 1 � ����� ����� 
				if (a[i+1] != 0) { // ���������, ����� �� ��������� ����� ���� ��� ���
					if (zeronum%2 == 0){
						j = j + 2; // ���� ����� ����� ������, �� ���������� � ����� ������� 2 � �������� �������
						zeronum = 0;
					} else {
						j = j + 1; // ���� ��������, �� ���������� � ����� ������� 1 � �������� �������
						zeronum = 0;
					}
				} 
			}
		} else {
			if (a[i] != 0){ // ���� ��������� ����� �� ����� ����, �� ���������� ��� ����
				j++;
			} else {
				zeronum++; // � ���� ��������� ����� - ����, �� ���������, ������� �������� � ��������
				if (zeronum%2 == 0){
					j = j + 2; // ���� ����� ����� ������, �� ���������� � ����� ������� 2 � �������� �������
					zeronum = 0;
				} else {
					j = j + 1; // ���� ��������, �� ���������� � ����� ������� 1 � �������� �������
					zeronum = 0;
				}
			}
		}
	}
	
	// printf("The length of out is %d\n", j);
	int *b = new int [j]; // �������� ������ ������ �������

	if (b == NULL) { // ���������, ���������� �� ������
		printf ("No free memory!\n");
		return 0;
	}
	
	printf("\nOutput: ");
	for (i = 0; i < n; i++) { // ����� ���������� �� ������������ �������, �� ��� ��������� ����� ������, ����� �������� ������ � ���������� �����
		if (i != n-1) {
			if (a[i] !=0){ // �� ���������� ������� �����, �� ��� ���� ������� k ��� ������ � ����� ������
				b[k] = a[i];
				k++;
			} else {
				zeronum++;
				if (a[i+1] != 0) { // ���������, ����� �� ��������� ����� ���� ��� ���
					if (zeronum%2 == 0){
						b[k] = 0;
						b[k+1] = 0;
						k = k + 2; // ���� ����� ����� ������, �� ���������� � ����� ������� 2 � �������� �������
						zeronum = 0;
					} else {
						b[k] = 0;
						k++; // ���� ��������, �� ���������� � ����� ������� 1 � �������� �������
						zeronum = 0;
					}
				} 
			}
		} else {
			if (a[i] != 0){ // ���� ��������� ����� �� ����� ����, �� ���������� ��� ����
				b[k] = a[i];
				k++;
			} else {
				zeronum++; // � ���� ��������� ����� - ����, �� ���������, ������� �������� � ��������
				if (zeronum%2 == 0){
						b[k] = 0;
						b[k+1] = 0;
						k = k + 2; // ���� ����� ����� ������, �� ���������� � ����� ������� 2 � �������� �������
						zeronum = 0;
					} else {
						b[k] = 0;
						k++; // ���� ��������, �� ���������� � ����� ������� 1 � �������� �������
						zeronum = 0;
				}
			}
		}
	}

	for (i = 0; i < j; i++){
		printf("%d ", b[i]);
	}

	delete[] b; // ����������� ������
}