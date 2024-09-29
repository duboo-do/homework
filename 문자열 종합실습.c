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
	printf("입력문자열: %s\n", input);
	for (int i = 0; i < 26; i++) printf("%c 출현횟수: %d\n", 'a' + i, count[i]);
	
	return 0;
}*/

#include <stdio.h>

int main() {
    char input[200] = "";
    int count[26] = { 0 }; // 소문자 
    int upper_count = 0; // 대문자 
    int number_count = 0; // 숫자
    int special_count = 0; // 특수문자 
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

    printf("입력문자열: %s\n", input);
    for (int j = 0; j < 26; j++) {
        printf("%c 출현횟수: %d\n", 'a' + j, count[j]);
    }
    printf("대문자 출현횟수: %d\n", upper_count);
    printf("숫자 출현횟수: %d\n", number_count);
    printf("특수문자 출현횟수: %d\n", special_count);

    return 0;
}
