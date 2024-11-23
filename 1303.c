/***********************************************
Practice 1. 명령라인 입력방법과 atoi 함수 사용
***********************************************/
#include <stdio.h>
#include <stdlib.h>
/*int atoi(char* num);*///문자열로받은 숫자형식으로 된 것을을 숫자로 변환
int main(int argc, char* argv[]){
    
    int a,b;
    /*for(int i=0; i<argc;i++){
        puts(argv[i]);
    }*/
    a=atoi(argv[1]);
    b=atoi(argv[2]);
    
    printf("a+b=%d", a+b);
    
    return 0;
}