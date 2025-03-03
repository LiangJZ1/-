#include <stdio.h>
#include <string.h>
#include "user_login.h" 
#include "user_register.h"

int main()
{
    for(;1;)
    {
        int a;
        int b;
        char tmp_char[100];
        FILE*file=fopen("config.ini","r");
        if (file == NULL)
        {
            file=fopen("config.ini","w");
            fprintf(file,"[admin]\n");
            printf("首次使用,已创建配置文件config.ini");
            printf("请先设置管理员密码\n");
            printf("请输入管理员密码:>");
            scanf("%99s",&tmp_char);
            fprintf(file, "password=%s\n",tmp_char);
            fprintf(file, "money=0\n");
            fprintf(file, "discount=10\n");
        }
        fclose(file); 
        FILE*room_file=fopen("room.ini","r");
        if (room_file == NULL)
        {
            fopen("room.ini","w");
            printf("已创建房间文件config.ini\n");
        }
        fclose(room_file); 
        printf("**********欢迎使用旅馆小帮手**********\n");
        printf("--------------1.登陆----------------\n");
        printf("--------------2.注册----------------\n");
        printf("--------------0.退出----------------\n");
        printf("请输入:>");
        scanf("%d",&a);
        if(a==1)
        {
            user_login();
        }
        else if(a==2)
        {
            user_register();
        }
        else if(a==0)
        {
            return 0;
        }
        else 
        {
            printf("输入错误，请重新输入\n");
        }
    }

}  
