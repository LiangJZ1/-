#ifndef FOUND_KEY_H
#define FOUND_KEY_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//用于查找config.ini的值（节，键）
char* found_key_char(char* input_title,char* input_key)
{
    char tmp_title[100];
    char line[1000];
    static char tmp_return[100];
    FILE*file=fopen("config.ini","r");
    while (fgets(line, sizeof(line), file))     //逐行读取到line
    {
        line[strcspn(line, "\n")] = '\0';    //去除换行符
        if(line[0] == '[' && line[strlen(line) - 1] == ']')     //找到[]
            {
                strncpy(tmp_title,line + 1,strlen(line) - 2);   //去除[];写入tmp_title
                tmp_title[strlen(line) - 2] = '\0';
                continue;
            }
        if(strstr(line,input_key)!=NULL)
        {
            if(strcmp(tmp_title,input_title)==0)
            {
                char *equal_sign = strchr(line,'=');
                strcpy(tmp_return, equal_sign + 1);
            }
        }
    }
    fclose(file); 
    return tmp_return;
}



#endif
