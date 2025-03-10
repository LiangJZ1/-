#ifndef FOUND_KEY_ROOM_H
#define FOUND_KEY_ROOM_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//用于查找room.ini的值（节，键）
char* found_key_char_room(char* input_title,char* input_key)
{
    char tmp_title[100];
    char line[1000];
    static char tmp_room_return[100];
    FILE*room_file=fopen("room.ini","r");
    while (fgets(line, sizeof(line), room_file))     //逐行读取到line
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
                strcpy(tmp_room_return, equal_sign + 1);
            }
        }
    }
    fclose(room_file); 
    return tmp_room_return;
}

#endif



