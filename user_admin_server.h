#ifndef USER_ADMIN_SERVER_H
#define USER_ADMIN_SERVER_H
#include <stdio.h>
#include <stdlib.h>
#include "data_change.h"
#include "found_key.h"
#include "room_change.h"
int user_admin_server()
{
    for(;1;)
    {
        double money=atof(found_key_char("admin","money"));
        int discount=atoi(found_key_char("admin","discount"));
        int choose;
        char line[1000];
        char title[100];
        char input_username[100];
        printf("**********��ӭʹ���ù�С����**********\n");
        printf("��ӭ�˿�:admin ��ǰ���:%.2lf  �����ۿ�:%d\n",money,discount);
        printf("--------------1.�޸ķ���----------------\n");
        printf("--------------2.�޸��û��ۿ�------------\n");
        printf("--------------3.����-------------------\n");
        printf("--------------4.�˷�-------------------\n");
        printf("--------------5.�鿴�ҵķ���------------\n");
        printf("--------------6.��ֵ-------------------\n");
        printf("--------------0.�˳���¼----------------\n");
        printf("��ѡ��;>");
        scanf("%d",&choose);
        if(choose==1)
        {
            room_change();
        }
        else if (choose==2)
        {
            printf("***********************************\n");
            FILE*file=fopen("config.ini","r");
            while (fgets(line, sizeof(line), file))     //���ж�ȡ��line
            {
                line[strcspn(line, "\n")] = '\0';    //ȥ�����з�
                if(line[0] == '[' && line[strlen(line) - 1] == ']')     //�ҵ�[]
                {
                    strncpy(title,line + 1,strlen(line) - 2);
                    title[strlen(line) - 2] = '\0';
                    if(strcmp(title,"data")!=0)
                    {
                        printf("%s\n",title);
                    }
                }
            }
            fclose(file);
            printf("��������Ҫ���ĵ��û�:>");
            scanf("%99s",input_username);
            printf("��������Ҫ���ĵ��ۿ�:>");
            int a;
            scanf("%d",&a);
            if(data_change_number(input_username,"discount",a)==0)
            {
                printf("�޸ĳɹ�\n");
            }
            else
            {
                printf("�޸�ʧ��\n");
            }
        }
        else if(choose==3)
        {
            char tmp_title[100];
            char tmp_char[100];
            printf("*********���з���*************\n");
            FILE*room_file=fopen("room.ini","r+");
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
            printf("��ѡ��Ҫ���ĵķ����:>");
            scanf("%99s",tmp_char);
            room_file=fopen("room.ini","r+");
            fseek(room_file, 0, SEEK_SET);                   //���ù�굽��ͷ
            while (fgets(line, sizeof(line), room_file))     //���ж�ȡ��line
            {
                line[strcspn(line, "\n")] = '\0';    
                if(line[0] == '[' && line[strlen(line) - 1] == ']')     //�ҵ�[]
                {
                    strncpy(tmp_title,line + 1,strlen(line) - 2);   //ȥ��[];д��tmp_title
                    tmp_title[strlen(line) - 2] = '\0';
                    if(strcmp(tmp_title,tmp_char)==0)
                    {
                        if(strcmp(found_key_char_room(tmp_title,"customer"),"no_people")==0)
                        {
                            double tmp_money=atof(found_key_char("admin","money"));
                            double money=atof(found_key_char_room(tmp_title,"money"));
                            double vip_money=(money*discount/10.0);
                            printf("�������� %.2lf ��Ǯ,�Ƿ����(1.��/2.��):>",vip_money);
                            int a;
                            scanf("%d",&a);
                            if(a==1)
                            {
                                if(tmp_money>vip_money)
                                {
                                    tmp_money=tmp_money-vip_money;
                                    fclose(room_file);
                                    data_change_number("admin","money",tmp_money);
                                    data_change_char_room(tmp_title,"customer","admin");
                                    printf("�����ɹ�������\n");
                                }
                                else
                                {
                                    printf("����\n");
                                    fclose(room_file);
                                }
                            }
                            else
                            {
                                printf("ȡ������\n");
                                fclose(room_file);
                            }
                        }
                        else
                        {
                            printf("�����ѱ���\n");
                            fclose(room_file);
                        }
    
                    }
                }
            }
    
            fclose(room_file);
        }
        else if(choose==4)
        {
            char tmp_title[100];
            char tmp_customer[100];
            printf("***********��ķ���*************\n");
            FILE*room_file=fopen("room.ini","r+");
            fseek(room_file, 0, SEEK_SET);  
            while (fgets(line, sizeof(line), room_file))
            {
                line[strcspn(line, "\n")] = '\0';    
                if(line[0] == '[' && line[strlen(line) - 1] == ']')     //�ҵ�[]
                {
                    strncpy(tmp_title,line + 1,strlen(line) - 2);   //ȥ��[];д��tmp_title
                    tmp_title[strlen(line) - 2] = '\0'; 
                    strcpy(tmp_customer,found_key_char_room(tmp_title,"customer"));
                    //printf("text%stext\n",tmp_customer);
                    if(strcmp(tmp_customer,"admin")==0)
                    {
                        printf("%s\n",tmp_title);
                    }
                }
            }
            fclose(room_file);
            printf("������Ҫ�˵ķ���,����0����:>");
            char tmp_room[100];
            scanf("%99s",tmp_room);
            if (strcmp(tmp_room, "0\0") == 0) 
            {
    
            }
            else
            {
    
                FILE*room_file=fopen("room.ini","r+");
                fseek(room_file, 0, SEEK_SET);  
                while (fgets(line, sizeof(line), room_file))
                {
                    line[strcspn(line, "\n")] = '\0';    
                    if(line[0] == '[' && line[strlen(line) - 1] == ']')     //�ҵ�[]
                    {
                        strncpy(tmp_title,line + 1,strlen(line) - 2);   //ȥ��[];д��tmp_title
                        tmp_title[strlen(line) - 2] = '\0'; 
                        if(strcmp(tmp_title,tmp_room)==0)
                        {
                            char tmp_a[100];
                            strcpy(tmp_a,found_key_char_room(tmp_room,"customer"));
                            if(strcmp(tmp_a,"admin")==0)
                            {
                                fclose(room_file);
                                data_change_char_room(tmp_room,"customer","no_people");
                                printf("���˷�\n");
    
                            }
                            else
                            {
                                fclose(room_file);
                                printf("�÷��������\n");
    
                            }
                        }
                    }
                }
                fclose(room_file);
    
    
            }
        }
        else if(choose==5)
        {
            char tmp_title[100];
            char tmp_customer[100];
            printf("***********��ķ���*************\n");
            FILE*room_file=fopen("room.ini","r+");
            fseek(room_file, 0, SEEK_SET);  
            while (fgets(line, sizeof(line), room_file))
            {
                line[strcspn(line, "\n")] = '\0';    
                if(line[0] == '[' && line[strlen(line) - 1] == ']')     //�ҵ�[]
                {
                    strncpy(tmp_title,line + 1,strlen(line) - 2);   //ȥ��[];д��tmp_title
                    tmp_title[strlen(line) - 2] = '\0'; 
                    strcpy(tmp_customer,found_key_char_room(tmp_title,"customer"));
                    //printf("text%stext\n",tmp_customer);
                    if(strcmp(tmp_customer,"admin")==0)
                    {
                        printf("%s\n",tmp_title);
                    }
                }
            }
            fclose(room_file);
    
        }
        else if(choose==6)
        {
            double tmp_money=atof(found_key_char("admin","money"));
            printf("���н��%.2lf",tmp_money);
            printf("��������Ҫ��ֵ�Ľ��:>");
            double input_money;
            scanf("%lf",&input_money);
            tmp_money=tmp_money+input_money;
            data_change_number("admin","money",tmp_money);
            printf("��ֵ�ɹ�,��ֵ��Ľ��Ϊ%lf\n",atof(found_key_char("admin","money")));
    
        }
        else if(choose==0)
        {
            return 0;
        }
        else
        {
            printf("�������,����������");
    
        }
    }
}
#endif
