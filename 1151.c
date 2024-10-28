#include <stdio.h>
int getLine(char* line)
{
    int ch;
    int i=0;
    while ((ch = getchar()) != '\n') line[i++] = ch;//문자 배열의 크기, 자기가 입력받은 길이
    line [i]='\0';
    return i;
}
int main() {
	char input[100];
	FILE* fp_src;
	FILE* fp_dest;
	if((fp_src = fopen("output.txt", "r"))==NULL){
	    printf("error...");
	    return 0;//시스템 잘못되거나 오류났을때 실행행
	}
	if((fp_dest = fopen("output2.txt", "w"))==NULL){
	    printf("error...");
	    return 0;
	}
	while(!feof(fp_src)){//feof가 아니면 동작한다
	    fgets(input,100,fp_src);
	   // printf("%s",input);
	    //puts(input);
	    printf("출력중");
	    fputs(input,fp_dest);
	    
	    //여기서 내가 원하는 작업을 하면 된다.
	    
	}
	
	fclose(fp_src);
	fclose(fp_dest);
	return 0;
}
