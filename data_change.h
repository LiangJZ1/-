#ifndef DATA_CHANGE_H
#define DATA_CHANGE_H
#include <stdio.h>
#include <string.h>

//��������������޸����ݵ�4�ֺ���������ƥ��ں��޸ļ�ֵ��

//�޸�config�ַ���ֵ
int data_change_char(char* input_title,char* input_key,char* input_data)
{
    char data[100];
    strcpy(data,input_data);
    char tmp_title[100];
    char line[1000];
    FILE*file=fopen("config.ini","r");
    FILE *temp_file = fopen("temp.ini", "w");       //������ʱ�ļ�
    fseek(file, 0, SEEK_SET);  
    while (fgets(line, sizeof(line), file))     //���ж�ȡ��line
    {
        line[strcspn(line, "\n")] = '\0';    //ȥ�����з�
        if(line[0] == '[' && line[strlen(line) - 1] == ']')     //�ҵ�[]
            {
                strncpy(tmp_title,line + 1,strlen(line) - 2);   //ȥ��[];д��tmp_title
                tmp_title[strlen(line) - 2] = '\0';
                line[strcspn(line, "\0")] = '\n';
                fprintf(temp_file,line);
                continue;
            }
        if(strstr(line,input_key)!=NULL)
            {
                if(strcmp(tmp_title,input_title)==0)
                {
                    fprintf(temp_file,"%s=%s\n",input_key,data);        //д���޸ĺ������
                    continue;
                }
                else 
                {
                    line[strcspn(line, "\0")] = '\n';
                    fprintf(temp_file,line);                        //��������
                    continue;
                }
            }
        else
            {
                line[strcspn(line, "\0")] = '\n';
                fprintf(temp_file,line);                            //��������
            }
    }
    fclose(file); 
    fclose(temp_file); 
    remove("config.ini");
    rename("temp.ini","config.ini");           //�滻�ļ�
    return 0;
}


//�޸�config���ֵ�ֵ
int data_change_number(char* input_title,char* input_key,double input_data)
{
    double data=input_data;
    char tmp_title[100];
    char line[1000];
    FILE*file=fopen("config.ini","r");
    FILE *temp_file = fopen("temp.ini", "w");       //������ʱ�ļ�
    fseek(file, 0, SEEK_SET);  
    while (fgets(line, sizeof(line), file))     //���ж�ȡ��line
    {
        line[strcspn(line, "\n")] = '\0';    //ȥ�����з�
        if(line[0] == '[' && line[strlen(line) - 1] == ']')     //�ҵ�[]
            {
                strncpy(tmp_title,line + 1,strlen(line) - 2);   //ȥ��[];д��tmp_title
                tmp_title[strlen(line) - 2] = '\0';
                line[strcspn(line, "\0")] = '\n';
                fprintf(temp_file,line);
                continue;
            }
        if(strstr(line,input_key)!=NULL)
            {
                if(strcmp(tmp_title,input_title)==0)
                {
                    fprintf(temp_file,"%s=%lf\n",input_key,data);        //д���޸ĺ������
                    continue;
                }
                else 
                {
                    line[strcspn(line, "\0")] = '\n';
                    fprintf(temp_file,line);                //��������
                    continue;
                }
            }
        else
            {
                line[strcspn(line, "\0")] = '\n';
                fprintf(temp_file,line);                    //��������
            }
    }
    fclose(file); 
    fclose(temp_file); 
    remove("config.ini");
    rename("temp.ini","config.ini");           //�滻�ļ�
    return 0;
}






//�޸�room���ֵ�ֵ
int data_change_number_room(char* input_title,char* input_key,double input_data)
{
    double data=input_data;
    char tmp_title[100];
    char line[1000];
    FILE*file=fopen("room.ini","r");
    FILE *temp_file = fopen("temp.ini", "w");       //������ʱ�ļ�
    fseek(file, 0, SEEK_SET);  
    while (fgets(line, sizeof(line), file))     //���ж�ȡ��line
    {
        line[strcspn(line, "\n")] = '\0';    //ȥ�����з�
        if(line[0] == '[' && line[strlen(line) - 1] == ']')     //�ҵ�[]
            {
                strncpy(tmp_title,line + 1,strlen(line) - 2);   //ȥ��[];д��tmp_title
                tmp_title[strlen(line) - 2] = '\0';
                line[strcspn(line, "\0")] = '\n';
                fprintf(temp_file,line);
                continue;
            }
        if(strstr(line,input_key)!=NULL)
            {
                if(strcmp(tmp_title,input_title)==0)
                {
                    fprintf(temp_file,"%s=%lf\n",input_key,data);        //д���޸ĺ������
                    continue;
                }
                else 
                {
                    line[strcspn(line, "\0")] = '\n';
                    fprintf(temp_file,line);                        //��������
                    continue;
                }
            }
        else
            {
                line[strcspn(line, "\0")] = '\n';
                fprintf(temp_file,line);                        //��������
            }
    }
    fclose(file); 
    fclose(temp_file); 
    remove("room.ini");
    rename("temp.ini","room.ini");           //�滻�ļ�
    return 0;
}




//�޸�room�ַ���ֵ
int data_change_char_room(char* input_title,char* input_key,char* input_data)
{
    char data[100];
    strcpy(data,input_data);
    char tmp_title[100];
    char line[1000];
    FILE*file=fopen("room.ini","r");
    FILE *temp_file = fopen("temp.ini", "w");       //������ʱ�ļ�
    fseek(file, 0, SEEK_SET);  
    while (fgets(line, sizeof(line), file))     //���ж�ȡ��line
    {
        line[strcspn(line, "\n")] = '\0';    //ȥ�����з�
        if(line[0] == '[' && line[strlen(line) - 1] == ']')     //�ҵ�[]
            {
                strncpy(tmp_title,line + 1,strlen(line) - 2);   //ȥ��[];д��tmp_title
                tmp_title[strlen(line) - 2] = '\0';
                line[strcspn(line, "\0")] = '\n';
                fprintf(temp_file,line);
                continue;
            }
        if(strstr(line,input_key)!=NULL)
            {
                if(strcmp(tmp_title,input_title)==0)
                {
                    fprintf(temp_file,"%s=%s\n",input_key,data);        //д���޸ĺ������
                    continue;
                }
                else 
                {
                    line[strcspn(line, "\0")] = '\n';
                    fprintf(temp_file,line);                    //��������
                    continue;
                }
            }
        else
            {
                line[strcspn(line, "\0")] = '\n';
                fprintf(temp_file,line);                        //��������
            }
    }
    fclose(file); 
    fclose(temp_file); 
    remove("room.ini");
    rename("temp.ini","room.ini");           //�滻�ļ�
    return 0;
}



#endif