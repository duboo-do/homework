#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
int main() {
	int number[SIZE];
	int most;
	int temp;
	srand(time(NULL));

	for (int i = 0; i < SIZE; i++) {
		number[i] = (rand() % 10000) + 1;
	}
	//�����ϴ� �κ�(14~24)
	//�� ū�� ã�°�
	for (int i = 0; i < SIZE; i++) {
		most = i;
	//��������� ���� ū ���� �˻�, ���� ū���� �ִ� �濡 �ε����� most�� �ִ� ������ ��
		for (int j = i + 1; j < SIZE; j++) {
			if (number[most] < number[j]) most = j;
		}
		//��ȯ
		temp = number[i];
		number[i] = number[most];
		number[most] = temp;
	}
	for (int i = 0; i < SIZE; i++) {
		printf("%5d\t", number[i]);
		if ((i + 1) % 10 == 0)printf("\n");
	}
}