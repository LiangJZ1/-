#ifndef USER_REGISTER_H
#define USER_REGISTER_H
#include <stdio.h>
#include <string.h>
//ע�Ṧ��
void user_register()
{
    int choose;
    char line[1000];
    char input_username[100];
    char input_password[100];
    char title[100];
    char tmpchar[100];
    int member;
    printf("********��ӭע��***********\n");
    printf("------1.�û�ע��-------\n");
    printf("----��-0.����--------------\n");
    printf("������ѡ��:>");
    scanf("%d",&choose);
    if(choose==1)
    {
        FILE*file=fopen("config.ini","a+");
        printf("�������û���:>");
        scanf("%99s",input_username);
        fseek(file, 0, SEEK_SET);                   //���ù�굽��ͷ
        while (fgets(line, sizeof(line), file))     //���ж�ȡ��line
        {
            line[strcspn(line, "\n")] = '\0';    //ȥ�����з�
            if (strstr(line, input_username) != NULL)  
            {
                sscanf(line,"user_name=%s",tmpchar);
                if(strcmp(input_username,tmpchar)==0)
                {
                    printf("���û��Ѿ�ע��,��ȥ��¼\n");
                    fclose(file); 
                }
            }
        }
        fseek(file, 0, SEEK_END);                   //���ù�굽ĩβ
        fprintf(file,"[%s]\n",input_username);
        fprintf(file,"discount=10\n");
        fprintf(file,"user_name=%s\n",input_username);
        printf("����������:>");
        scanf("%99s",input_password);                           //д���û���Ϣ
        fprintf(file,"password=%s\n",input_password);
        fprintf(file,"money=0\n");
        fclose(file); 
        printf("�����������,�û�ע��ɹ�����ȥ��½\n");
        user_login() ;
    }
    else if(choose==0)
    {
        extern int main();
        main();
    }
    else
    {
        printf("��������,����������\n");
        user_register();
    }
}
#endif