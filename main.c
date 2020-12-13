#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void delsp(char*s,char*r)
{
    int dot=0,i=0;
    while(s[i++]!='\0')if(s[i]=='.')dot=1;
    char*word=strtok(s," .");
    while(word!=NULL)
    {
        while(*word!='\0')
        {
            if(*word=='.') return;
            *r++=*word;
            word++;
        }
        word=strtok(NULL," .");
        if(word!=NULL)
        *r++=' ';
    }
    if(dot)*r++='.';
    *r++='\0';
}

int main()
{
    SetConsoleOutputCP(1251);
    //SetConsoleCP(1251);
    char str[256],str2[256],str3[256],*s,*s2,*s3,*word;
    s=str;
    s2=str2;
    s3=str3;
    printf("Task 10\n");
    gets(s);
    delsp(s,s2);
    printf("Без лишних пробелов(1A):\n");
    puts(s2);

    printf("Файловый ввод-вывод\n");
    printf("Строка из задания А1 запишется в файл, а затем выведется\n");
    FILE *f=fopen("MyFile.txt","w");
    fputs(s2,f);
    fclose(f);
    f=fopen("MyFile.txt","r");
    fgets(s3,255,f);
    puts(s3);
    fclose(f);
    return 0;
}
