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
            printf("�״�ʹ��,�Ѵ��������ļ�config.ini");
            printf("�������ù���Ա����\n");
            printf("���������Ա����:>");
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
            printf("�Ѵ��������ļ�config.ini\n");
        }
        fclose(room_file); 
        printf("**********��ӭʹ���ù�С����**********\n");
        printf("--------------1.��½----------------\n");
        printf("--------------2.ע��----------------\n");
        printf("--------------0.�˳�----------------\n");
        printf("������:>");
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
            printf("�����������������\n");
        }
    }

}  
