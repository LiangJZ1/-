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
        printf("**********欢迎登陆**********\n");
        printf("--------1.管理员登陆--------\n");
        printf("--------2.用户登陆----------\n");
        printf("--------0.返回--------------\n");
        printf("请选择:>");
        scanf("%d",&choose);
        if(choose==1)
        {
            printf("请输入管理员密码:>");               //管理员登陆
            scanf("%99s",input_password);
            FILE*file=fopen("config.ini","r");
            while (fgets(line, sizeof(line), file))     //逐行读取到line
            {
                line[strcspn(line, "\n")] = '\0';    //去除换行符
                if(line[0] == '[' && line[strlen(line) - 1] == ']')     //找到[]
                {
                    strncpy(title,line + 1,strlen(line) - 2);   //去除[]
                    continue;
                }
                if (strstr(line, "password") != NULL)       //找到密码
                {
                    if(strstr(title,"admin")!=NULL)         
                    {
                        sscanf(line,"password=%s",tmp_password);       //提取密码保存到tmp_password
                        break;
                    }
                }
            }
            fclose(file);
            if(strcmp(input_password,tmp_password)==0)
            {
                printf("密码正确，欢迎登陆\n");
                user_admin_server();                    //校验密码
            }
            else
            {
                printf("密码错误，请重新登陆\n");
            }
        }
        else if(choose==2)                            //用户登陆
        {
            printf("请输入用户名:>");
            scanf("%99s",input_username);
            FILE*file=fopen("config.ini","r");
            while (fgets(line, sizeof(line), file))                 //逐行读取配置文件
            {
                line[strcspn(line, "\n")] = '\0';
                sprintf(tmp_data,"user_name=%s",input_username);
                if(strcmp(line,tmp_data)==0)                            //校验用户名
                {
                    printf("请输入%s用户密码:>",input_username);
                    scanf("%99s",input_password);
                    username_found=1;
                    continue;
                }
                if(username_found)
                {
                    if (strstr(line, "password") != NULL)
                    {
                    sscanf(line,"password=%s",tmp_password);
                    break;                                              //读取密码
                    }
                }
            }
            fclose(file);
            if(strcmp(input_password,tmp_password)==0)
            {
                printf("密码正确，欢迎登陆\n");
                user_server(input_username);                         //校验密码
            }
            else
            {
                printf("密码错误，或者不存在用户，请重新登陆\n");
            }
    
        }
        else if(choose==0)
        {
            return 0;
        }
        else 
        {
            printf("输入错误,请重新输入\n");
        }
    }


}
#endif