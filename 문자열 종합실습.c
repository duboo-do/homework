/*#include <stdio.h>

int main() {
	char input[200] = "";
	int count[26] = { 0 };
	int ch;
	int i = 0;

	while ((ch = getchar()) != EOF) {
		input[i++] = ch;
	}
	i = 0;
	while (input[i] != '\0') {
		if (input[i] >= 'a' && input[i] <= 'z') {
			count[input[i] - 'a']++;
		}
		i++;
	}
	printf("�Է¹��ڿ�: %s\n", input);
	for (int i = 0; i < 26; i++) printf("%c ����Ƚ��: %d\n", 'a' + i, count[i]);
	
	return 0;
}*/

#include <stdio.h>

int main() {
    char input[200] = "";
    int count[26] = { 0 }; // �ҹ��� 
    int upper_count = 0; // �빮�� 
    int number_count = 0; // ����
    int special_count = 0; // Ư������ 
    int ch;
    int i = 0;

    while ((ch = getchar()) != EOF) {
        input[i++] = ch;
    }
    input[i] = '\0';

    i = 0;
    while (input[i] != '\0') {
        if (input[i] >= 'a' && input[i] <= 'z') {
            count[input[i] - 'a']++;
        }
        else if (input[i] >= 'A' && input[i] <= 'Z') {
            upper_count++;
        }
        else if (input[i] >= '0' && input[i] <= '9') {
            number_count++;
        }
        else {
            special_count++;
        }
        i++;
    }

    printf("�Է¹��ڿ�: %s\n", input);
    for (int j = 0; j < 26; j++) {
        printf("%c ����Ƚ��: %d\n", 'a' + j, count[j]);
    }
    printf("�빮�� ����Ƚ��: %d\n", upper_count);
    printf("���� ����Ƚ��: %d\n", number_count);
    printf("Ư������ ����Ƚ��: %d\n", special_count);

    return 0;
}
