#ifndef USER_LOGIN_H
#define USER_LOGIN_H
#include <stdio.h>
#include <string.h>
#include "user_admin_server.h"
#include "user_server.h"
int user_login() 
{
    for(;1;)
    {
        char input_password[100];
        char input_username[100];
        char tmp_password[100];
        char line[1000];
        char title[100];
        char tmp_data[200];
        int username_found=0;
        int choose;
        printf("**********��ӭ��½**********\n");
        printf("--------1.����Ա��½--------\n");
        printf("--------2.�û���½----------\n");
        printf("--------0.����--------------\n");
        printf("��ѡ��:>");
        scanf("%d",&choose);
        if(choose==1)
        {
            printf("���������Ա����:>");               //����Ա��½
            scanf("%99s",input_password);
            FILE*file=fopen("config.ini","r");
            while (fgets(line, sizeof(line), file))     //���ж�ȡ��line
            {
                line[strcspn(line, "\n")] = '\0';    //ȥ�����з�
                if(line[0] == '[' && line[strlen(line) - 1] == ']')     //�ҵ�[]
                {
                    strncpy(title,line + 1,strlen(line) - 2);   //ȥ��[]
                    continue;
                }
                if (strstr(line, "password") != NULL)       //�ҵ�����
                {
                    if(strstr(title,"admin")!=NULL)         
                    {
                        sscanf(line,"password=%s",tmp_password);       //��ȡ���뱣�浽tmp_password
                        break;
                    }
                }
            }
            fclose(file);
            if(strcmp(input_password,tmp_password)==0)
            {
                printf("������ȷ����ӭ��½\n");
                user_admin_server();                    //У������
            }
            else
            {
                printf("������������µ�½\n");
            }
        }
        else if(choose==2)                            //�û���½
        {
            printf("�������û���:>");
            scanf("%99s",input_username);
            FILE*file=fopen("config.ini","r");
            while (fgets(line, sizeof(line), file))                 //���ж�ȡ�����ļ�
            {
                line[strcspn(line, "\n")] = '\0';
                sprintf(tmp_data,"user_name=%s",input_username);
                if(strcmp(line,tmp_data)==0)                            //У���û���
                {
                    printf("������%s�û�����:>",input_username);
                    scanf("%99s",input_password);
                    username_found=1;
                    continue;
                }
                if(username_found)
                {
                    if (strstr(line, "password") != NULL)
                    {
                    sscanf(line,"password=%s",tmp_password);
                    break;                                              //��ȡ����
                    }
                }
            }
            fclose(file);
            if(strcmp(input_password,tmp_password)==0)
            {
                printf("������ȷ����ӭ��½\n");
                user_server(input_username);                         //У������
            }
            else
            {
                printf("������󣬻��߲������û��������µ�½\n");
            }
    
        }
        else if(choose==0)
        {
            return 0;
        }
        else 
        {
            printf("�������,����������\n");
        }
    }


}
#endif