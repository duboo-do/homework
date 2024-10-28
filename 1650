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
	FILE* fp;
	if((fp = fopen("output.txt", "w"))==NULL){
	    printf("error...");
	    return 0;//시스템 잘못되거나 오류났을때 실행행
	};
	for(int i=0;i<5;i++){
	getLine(input);
	fputs(input,fp);
	fputs("\n",fp);
	}
	
	fclose(fp);
	return 0;
}
