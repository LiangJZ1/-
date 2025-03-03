#ifndef ROOM_CHANGE_H
#define ROOM_CHANGE_H
#include <stdio.h>
#include <string.h>
#include "found_key_room.h"
#include "room_delete.h"
#include "user_admin_server.h"
int room_change()
{
    for(;1;)
    {
        int choose;
        char line[1000];
        char tmp_title[100];
        char tmp_char[100];
        FILE*room_file;
        printf("**********欢迎使用旅馆小帮手**********\n");
        printf("-----------1.增加房间----------------\n");
        printf("-----------2.删除房间----------------\n");
        printf("-----------0.返回--------------------\n");
        scanf("%d",&choose);
        if(choose==1)
        {
            printf("*********现有房间*************\n");
            room_file=fopen("room.ini","r+");
            fseek(room_file, 0, SEEK_SET);  
            while (fgets(line, sizeof(line), room_file))
            {
                line[strcspn(line, "\n")] = '\0';    
                if(line[0] == '[' && line[strlen(line) - 1] == ']')     //找到[]
                {
                    strncpy(tmp_title,line + 1,strlen(line) - 2);   //去除[];写入tmp_title
                    tmp_title[strlen(line) - 2] = '\0';
                    printf("房间号:%s    ",tmp_title);
                    strcpy(tmp_char,found_key_char_room(tmp_title,"customer"));
                    printf("入住情况:%s  ",tmp_char);
                    strcpy(tmp_char,found_key_char_room(tmp_title,"type"));
                    printf("房间类型:%s  ",tmp_char);
                    strcpy(tmp_char,found_key_char_room(tmp_title,"money"));
                    printf("房间价格:%s  \n",tmp_char);
                }
            }
            fclose(room_file);
            char tmp_char_1[100];
            char tmp_char_2[100];
            char tmp_char_3[100];
            printf("请输入增加的房间号:>");
            scanf("%99s",tmp_char_1);
            room_file=fopen("room.ini","r+");
            fseek(room_file, 0, SEEK_SET);                   //重置光标到开头
            while (fgets(line, sizeof(line), room_file))     //逐行读取到line
            {
                line[strcspn(line, "\n")] = '\0';    
                if(line[0] == '[' && line[strlen(line) - 1] == ']')     //找到[]
                {
                    strncpy(tmp_title,line + 1,strlen(line) - 2);   //去除[];写入tmp_title
                    tmp_title[strlen(line) - 2] = '\0';
                    if(strcmp(tmp_title,tmp_char_1)==0)
                    {
                        printf("该房间已存在,请删除后重新设置\n");
                        fclose(room_file);
                    }
                }
            }
            printf("请输入增加的房间价格:>");
            scanf("%99s",tmp_char_2);
            printf("请输入增加的房间类型:>");
            scanf("%99s",tmp_char_3);
            fseek(room_file, 0, SEEK_END);  
            fprintf(room_file,"[%s]\n",tmp_char_1);
            fprintf(room_file,"money=%s\n",tmp_char_2);
            fprintf(room_file,"type=%s\n",tmp_char_3);
            fprintf(room_file,"customer=no_people\n");
            fclose(room_file);
            printf("添加完成\n");
            return 0;
        }
        else if (choose==2)
        {
            printf("*********现有房间*************\n");
            room_file=fopen("room.ini","r+");
            fseek(room_file, 0, SEEK_SET);  
            while (fgets(line, sizeof(line), room_file))
            {
                line[strcspn(line, "\n")] = '\0';    
                if(line[0] == '[' && line[strlen(line) - 1] == ']')     //找到[]
                {
                    strncpy(tmp_title,line + 1,strlen(line) - 2);   //去除[];写入tmp_title
                    tmp_title[strlen(line) - 2] = '\0';
                    printf("房间号:%s    ",tmp_title);
                    strcpy(tmp_char,found_key_char_room(tmp_title,"customer"));
                    printf("入住情况:%s  ",tmp_char);
                    strcpy(tmp_char,found_key_char_room(tmp_title,"type"));
                    printf("房间类型:%s  ",tmp_char);
                    strcpy(tmp_char,found_key_char_room(tmp_title,"money"));
                    printf("房间价格:%s  \n",tmp_char);
                }
            }
            fclose(room_file);
            printf("请输入需要删除的房间号:>");
            scanf("%99s",tmp_char);
            room_delete(tmp_char);
            printf("删除完成\n");
            return 0;
        }
        else if(choose==0)
        {
            return 0;
        }
        else
        {
            printf("输入错误，请重新输入\n");
        }
    }
}

#endif