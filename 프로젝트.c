#include <stdio.h>
#include <string.h>
#include <math.h>
#define WORD    16

void getBinary(char bin[],char str[], int n){
    int len = strlen(str); // 입력받은 문자열 길이
    for (int i = 0; i < n; i++) {
        if (i < len) {
            bin[n - 1 - i] = str[len - 1 - i]; // 뒤에서부터 채운다.
        } else {
            bin[n - 1 - i] = '0'; // 나머지는 0으로 채운다.
        }
    }
    bin[n] = '\0'; // 문자열의 끝을 표시
}
void complement2(char bin[], int n){
    // 1의 보수 계산
    for (int i = 0; i < n; i++) {
        bin[i] = (bin[i] == '0') ? '1' : '0'; // 0이면 1로, 1이면 0으로 반전
    }

    // 2의 보수 계산 (1의 보수에 1을 더한다)
    int carry = 1; // 1을 더하는 연산
    for (int i = n - 1; i >= 0; i--) {
        if (bin[i] == '0' && carry == 1) {
            bin[i] = '1';
            carry = 0; // 더 이상 더할 1이 없다
            break;
        }
        if (bin[i] == '1' && carry == 1) {
            bin[i] = '0';
        }
    }
}
int bin2dec(char bin[], int n){
    int result = 0;
    
    for (int i = 0; i < n; i++) {
        if (bin[i] == '1') {
            result += (1 << (n - 1 - i)); // 2^k를 더하는 방식으로 변환
        }
    }
    return result;
}
int main(){
    char input1[100];
    char input2[100];
    char op[10];
    
    char binary1[WORD+1]={0};
    char binary2[WORD+1]={0};
    
    int result;
    int num1, num2;
    
    printf("<<<<input>>>>>\n");
    gets(input1);
    gets(op);
    gets(input2);
    getBinary(binary1, input1, WORD);
    getBinary(binary1, input1, WORD);
    
    num1=bin2dec(binary1, WORD);
    num2=bin2dec(binary2, WORD);
    
    switch(op[0]){
        case'+':result=num1+num2;     break;
        case'-':result=num1-num2;     break;
        case'*':result=num1*num2;     break;
        case'/':result=num1/num2;     break;
        case'%':result=num1%num2;     break;
        defalt : printf("bad operator...\n");     break;
    }
    printf("%s(%d) %c %s(%d)=%d\n", binary1, num1, op[0], binary2, num2, result);
    return 0;
}
