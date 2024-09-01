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
	//정열하는 부분(14~24)
	//젤 큰값 찾는것
	for (int i = 0; i < SIZE; i++) {
		most = i;
	//다음방부터 제일 큰 값을 검색, 제일 큰값이 있는 방에 인덱스를 most에 넣는 역할을 함
		for (int j = i + 1; j < SIZE; j++) {
			if (number[most] < number[j]) most = j;
		}
		//교환
		temp = number[i];
		number[i] = number[most];
		number[most] = temp;
	}
	for (int i = 0; i < SIZE; i++) {
		printf("%5d\t", number[i]);
		if ((i + 1) % 10 == 0)printf("\n");
	}
}