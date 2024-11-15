/*#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int*pInt;//배열처럼 사용
    int count;
    
    scanf("%d", &count);
    pInt=(int*)malloc(count*sizeof(int));//실행되는 중간에 메모리 입력 받은거임
    
    for(int i=0; i<count;i++) pInt[i]=rand()%100;
    for(int i=0; i<count;i++) printf("%d ", pInt[i]);
    
    free(pInt);
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    char* pChar;
    int*pInt;//배열처럼 사용
    int count;
    
    scanf("%d", &count);
    pInt=(int*)malloc(count*sizeof(int));//실행되는 중간에 메모리 입력 받은거임
    
    for(int i=0; i<count;i++) pInt[i]=rand()%100;
    for(int i=0; i<count;i++) printf("%d ", pInt[i]);
    
    pChar=(char*)pInt;
    
    while(getchar()!='\n');//해결방법
    gets(pChar);//숫자입력하고 enter키가 여기 들어가버림
    puts(pChar);
    
    free(pInt);
    return 0;
}
