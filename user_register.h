#ifndef USER_REGISTER_H
#define USER_REGISTER_H
#include <stdio.h>
#include <string.h>
//注册功能
void user_register()
{
    int choose;
    char line[1000];
    char input_username[100];
    char input_password[100];
    char title[100];
    char tmpchar[100];
    int member;
    printf("********欢迎注册***********\n");
    printf("------1.用户注册-------\n");
    printf("----—-0.返回--------------\n");
    printf("请输入选择:>");
    scanf("%d",&choose);
    if(choose==1)
    {
        FILE*file=fopen("config.ini","a+");
        printf("请输入用户名:>");
        scanf("%99s",input_username);
        fseek(file, 0, SEEK_SET);                   //重置光标到开头
        while (fgets(line, sizeof(line), file))     //逐行读取到line
        {
            line[strcspn(line, "\n")] = '\0';    //去除换行符
            if (strstr(line, input_username) != NULL)  
            {
                sscanf(line,"user_name=%s",tmpchar);
                if(strcmp(input_username,tmpchar)==0)
                {
                    printf("该用户已经注册,请去登录\n");
                    fclose(file); 
                }
            }
        }
        fseek(file, 0, SEEK_END);                   //重置光标到末尾
        fprintf(file,"[%s]\n",input_username);
        fprintf(file,"discount=10\n");
        fprintf(file,"user_name=%s\n",input_username);
        printf("请设置密码:>");
        scanf("%99s",input_password);                           //写入用户信息
        fprintf(file,"password=%s\n",input_password);
        fprintf(file,"money=0\n");
        fclose(file); 
        printf("密码设置完成,用户注册成功，请去登陆\n");
        user_login() ;
    }
    else if(choose==0)
    {
        extern int main();
        main();
    }
    else
    {
        printf("输入有误,请重新输入\n");
        user_register();
    }
}
#endif