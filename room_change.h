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
        printf("**********��ӭʹ���ù�С����**********\n");
        printf("-----------1.���ӷ���----------------\n");
        printf("-----------2.ɾ������----------------\n");
        printf("-----------0.����--------------------\n");
        scanf("%d",&choose);
        if(choose==1)
        {
            printf("*********���з���*************\n");
            room_file=fopen("room.ini","r+");
            fseek(room_file, 0, SEEK_SET);  
            while (fgets(line, sizeof(line), room_file))
            {
                line[strcspn(line, "\n")] = '\0';    
                if(line[0] == '[' && line[strlen(line) - 1] == ']')     //�ҵ�[]
                {
                    strncpy(tmp_title,line + 1,strlen(line) - 2);   //ȥ��[];д��tmp_title
                    tmp_title[strlen(line) - 2] = '\0';
                    printf("�����:%s    ",tmp_title);
                    strcpy(tmp_char,found_key_char_room(tmp_title,"customer"));
                    printf("��ס���:%s  ",tmp_char);
                    strcpy(tmp_char,found_key_char_room(tmp_title,"type"));
                    printf("��������:%s  ",tmp_char);
                    strcpy(tmp_char,found_key_char_room(tmp_title,"money"));
                    printf("����۸�:%s  \n",tmp_char);
                }
            }
            fclose(room_file);
            char tmp_char_1[100];
            char tmp_char_2[100];
            char tmp_char_3[100];
            printf("���������ӵķ����:>");
            scanf("%99s",tmp_char_1);
            room_file=fopen("room.ini","r+");
            fseek(room_file, 0, SEEK_SET);                   //���ù�굽��ͷ
            while (fgets(line, sizeof(line), room_file))     //���ж�ȡ��line
            {
                line[strcspn(line, "\n")] = '\0';    
                if(line[0] == '[' && line[strlen(line) - 1] == ']')     //�ҵ�[]
                {
                    strncpy(tmp_title,line + 1,strlen(line) - 2);   //ȥ��[];д��tmp_title
                    tmp_title[strlen(line) - 2] = '\0';
                    if(strcmp(tmp_title,tmp_char_1)==0)
                    {
                        printf("�÷����Ѵ���,��ɾ������������\n");
                        fclose(room_file);
                    }
                }
            }
            printf("���������ӵķ���۸�:>");
            scanf("%99s",tmp_char_2);
            printf("���������ӵķ�������:>");
            scanf("%99s",tmp_char_3);
            fseek(room_file, 0, SEEK_END);  
            fprintf(room_file,"[%s]\n",tmp_char_1);
            fprintf(room_file,"money=%s\n",tmp_char_2);
            fprintf(room_file,"type=%s\n",tmp_char_3);
            fprintf(room_file,"customer=no_people\n");
            fclose(room_file);
            printf("������\n");
            return 0;
        }
        else if (choose==2)
        {
            printf("*********���з���*************\n");
            room_file=fopen("room.ini","r+");
            fseek(room_file, 0, SEEK_SET);  
            while (fgets(line, sizeof(line), room_file))
            {
                line[strcspn(line, "\n")] = '\0';    
                if(line[0] == '[' && line[strlen(line) - 1] == ']')     //�ҵ�[]
                {
                    strncpy(tmp_title,line + 1,strlen(line) - 2);   //ȥ��[];д��tmp_title
                    tmp_title[strlen(line) - 2] = '\0';
                    printf("�����:%s    ",tmp_title);
                    strcpy(tmp_char,found_key_char_room(tmp_title,"customer"));
                    printf("��ס���:%s  ",tmp_char);
                    strcpy(tmp_char,found_key_char_room(tmp_title,"type"));
                    printf("��������:%s  ",tmp_char);
                    strcpy(tmp_char,found_key_char_room(tmp_title,"money"));
                    printf("����۸�:%s  \n",tmp_char);
                }
            }
            fclose(room_file);
            printf("��������Ҫɾ���ķ����:>");
            scanf("%99s",tmp_char);
            room_delete(tmp_char);
            printf("ɾ�����\n");
            return 0;
        }
        else if(choose==0)
        {
            return 0;
        }
        else
        {
            printf("�����������������\n");
        }
    }
}

#endif