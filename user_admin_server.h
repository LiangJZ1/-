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
        printf("**********欢迎使用旅馆小帮手**********\n");
        printf("欢迎顾客:admin 当前余额:%.2lf  享受折扣:%d\n",money,discount);
        printf("--------------1.修改房间----------------\n");
        printf("--------------2.修改用户折扣------------\n");
        printf("--------------3.开房-------------------\n");
        printf("--------------4.退房-------------------\n");
        printf("--------------5.查看我的房间------------\n");
        printf("--------------6.充值-------------------\n");
        printf("--------------0.退出登录----------------\n");
        printf("请选择;>");
        scanf("%d",&choose);
        if(choose==1)
        {
            room_change();
        }
        else if (choose==2)
        {
            printf("***********************************\n");
            FILE*file=fopen("config.ini","r");
            while (fgets(line, sizeof(line), file))     //逐行读取到line
            {
                line[strcspn(line, "\n")] = '\0';    //去除换行符
                if(line[0] == '[' && line[strlen(line) - 1] == ']')     //找到[]
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
            printf("请输入想要更改的用户:>");
            scanf("%99s",input_username);
            printf("请输入想要更改的折扣:>");
            int a;
            scanf("%d",&a);
            if(data_change_number(input_username,"discount",a)==0)
            {
                printf("修改成功\n");
            }
            else
            {
                printf("修改失败\n");
            }
        }
        else if(choose==3)
        {
            char tmp_title[100];
            char tmp_char[100];
            printf("*********现有房间*************\n");
            FILE*room_file=fopen("room.ini","r+");
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
            printf("请选择要订阅的房间号:>");
            scanf("%99s",tmp_char);
            room_file=fopen("room.ini","r+");
            fseek(room_file, 0, SEEK_SET);                   //重置光标到开头
            while (fgets(line, sizeof(line), room_file))     //逐行读取到line
            {
                line[strcspn(line, "\n")] = '\0';    
                if(line[0] == '[' && line[strlen(line) - 1] == ']')     //找到[]
                {
                    strncpy(tmp_title,line + 1,strlen(line) - 2);   //去除[];写入tmp_title
                    tmp_title[strlen(line) - 2] = '\0';
                    if(strcmp(tmp_title,tmp_char)==0)
                    {
                        if(strcmp(found_key_char_room(tmp_title,"customer"),"no_people")==0)
                        {
                            double tmp_money=atof(found_key_char("admin","money"));
                            double money=atof(found_key_char_room(tmp_title,"money"));
                            double vip_money=(money*discount/10.0);
                            printf("即将消耗 %.2lf 块钱,是否继续(1.是/2.否):>",vip_money);
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
                                    printf("订购成功！！！\n");
                                }
                                else
                                {
                                    printf("余额不足\n");
                                    fclose(room_file);
                                }
                            }
                            else
                            {
                                printf("取消购买\n");
                                fclose(room_file);
                            }
                        }
                        else
                        {
                            printf("房间已被定\n");
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
            printf("***********你的房间*************\n");
            FILE*room_file=fopen("room.ini","r+");
            fseek(room_file, 0, SEEK_SET);  
            while (fgets(line, sizeof(line), room_file))
            {
                line[strcspn(line, "\n")] = '\0';    
                if(line[0] == '[' && line[strlen(line) - 1] == ']')     //找到[]
                {
                    strncpy(tmp_title,line + 1,strlen(line) - 2);   //去除[];写入tmp_title
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
            printf("请输入要退的房间,输入0返回:>");
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
                    if(line[0] == '[' && line[strlen(line) - 1] == ']')     //找到[]
                    {
                        strncpy(tmp_title,line + 1,strlen(line) - 2);   //去除[];写入tmp_title
                        tmp_title[strlen(line) - 2] = '\0'; 
                        if(strcmp(tmp_title,tmp_room)==0)
                        {
                            char tmp_a[100];
                            strcpy(tmp_a,found_key_char_room(tmp_room,"customer"));
                            if(strcmp(tmp_a,"admin")==0)
                            {
                                fclose(room_file);
                                data_change_char_room(tmp_room,"customer","no_people");
                                printf("已退房\n");
    
                            }
                            else
                            {
                                fclose(room_file);
                                printf("该房不是你的\n");
    
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
            printf("***********你的房间*************\n");
            FILE*room_file=fopen("room.ini","r+");
            fseek(room_file, 0, SEEK_SET);  
            while (fgets(line, sizeof(line), room_file))
            {
                line[strcspn(line, "\n")] = '\0';    
                if(line[0] == '[' && line[strlen(line) - 1] == ']')     //找到[]
                {
                    strncpy(tmp_title,line + 1,strlen(line) - 2);   //去除[];写入tmp_title
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
            printf("现有金额%.2lf",tmp_money);
            printf("请输入想要充值的金额:>");
            double input_money;
            scanf("%lf",&input_money);
            tmp_money=tmp_money+input_money;
            data_change_number("admin","money",tmp_money);
            printf("充值成功,充值后的金额为%lf\n",atof(found_key_char("admin","money")));
    
        }
        else if(choose==0)
        {
            return 0;
        }
        else
        {
            printf("输入错误,请重新输入");
    
        }
    }
}
#endif
