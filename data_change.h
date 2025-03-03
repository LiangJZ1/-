#ifndef DATA_CHANGE_H
#define DATA_CHANGE_H
#include <stdio.h>
#include <string.h>

//这里包含了用于修改数据的4种函数，用于匹配节和修改键值对

//修改config字符的值
int data_change_char(char* input_title,char* input_key,char* input_data)
{
    char data[100];
    strcpy(data,input_data);
    char tmp_title[100];
    char line[1000];
    FILE*file=fopen("config.ini","r");
    FILE *temp_file = fopen("temp.ini", "w");       //创建临时文件
    fseek(file, 0, SEEK_SET);  
    while (fgets(line, sizeof(line), file))     //逐行读取到line
    {
        line[strcspn(line, "\n")] = '\0';    //去除换行符
        if(line[0] == '[' && line[strlen(line) - 1] == ']')     //找到[]
            {
                strncpy(tmp_title,line + 1,strlen(line) - 2);   //去除[];写入tmp_title
                tmp_title[strlen(line) - 2] = '\0';
                line[strcspn(line, "\0")] = '\n';
                fprintf(temp_file,line);
                continue;
            }
        if(strstr(line,input_key)!=NULL)
            {
                if(strcmp(tmp_title,input_title)==0)
                {
                    fprintf(temp_file,"%s=%s\n",input_key,data);        //写入修改后的数据
                    continue;
                }
                else 
                {
                    line[strcspn(line, "\0")] = '\n';
                    fprintf(temp_file,line);                        //复制数据
                    continue;
                }
            }
        else
            {
                line[strcspn(line, "\0")] = '\n';
                fprintf(temp_file,line);                            //复制数据
            }
    }
    fclose(file); 
    fclose(temp_file); 
    remove("config.ini");
    rename("temp.ini","config.ini");           //替换文件
    return 0;
}


//修改config数字的值
int data_change_number(char* input_title,char* input_key,double input_data)
{
    double data=input_data;
    char tmp_title[100];
    char line[1000];
    FILE*file=fopen("config.ini","r");
    FILE *temp_file = fopen("temp.ini", "w");       //创建临时文件
    fseek(file, 0, SEEK_SET);  
    while (fgets(line, sizeof(line), file))     //逐行读取到line
    {
        line[strcspn(line, "\n")] = '\0';    //去除换行符
        if(line[0] == '[' && line[strlen(line) - 1] == ']')     //找到[]
            {
                strncpy(tmp_title,line + 1,strlen(line) - 2);   //去除[];写入tmp_title
                tmp_title[strlen(line) - 2] = '\0';
                line[strcspn(line, "\0")] = '\n';
                fprintf(temp_file,line);
                continue;
            }
        if(strstr(line,input_key)!=NULL)
            {
                if(strcmp(tmp_title,input_title)==0)
                {
                    fprintf(temp_file,"%s=%lf\n",input_key,data);        //写入修改后的数据
                    continue;
                }
                else 
                {
                    line[strcspn(line, "\0")] = '\n';
                    fprintf(temp_file,line);                //复制数据
                    continue;
                }
            }
        else
            {
                line[strcspn(line, "\0")] = '\n';
                fprintf(temp_file,line);                    //复制数据
            }
    }
    fclose(file); 
    fclose(temp_file); 
    remove("config.ini");
    rename("temp.ini","config.ini");           //替换文件
    return 0;
}






//修改room数字的值
int data_change_number_room(char* input_title,char* input_key,double input_data)
{
    double data=input_data;
    char tmp_title[100];
    char line[1000];
    FILE*file=fopen("room.ini","r");
    FILE *temp_file = fopen("temp.ini", "w");       //创建临时文件
    fseek(file, 0, SEEK_SET);  
    while (fgets(line, sizeof(line), file))     //逐行读取到line
    {
        line[strcspn(line, "\n")] = '\0';    //去除换行符
        if(line[0] == '[' && line[strlen(line) - 1] == ']')     //找到[]
            {
                strncpy(tmp_title,line + 1,strlen(line) - 2);   //去除[];写入tmp_title
                tmp_title[strlen(line) - 2] = '\0';
                line[strcspn(line, "\0")] = '\n';
                fprintf(temp_file,line);
                continue;
            }
        if(strstr(line,input_key)!=NULL)
            {
                if(strcmp(tmp_title,input_title)==0)
                {
                    fprintf(temp_file,"%s=%lf\n",input_key,data);        //写入修改后的数据
                    continue;
                }
                else 
                {
                    line[strcspn(line, "\0")] = '\n';
                    fprintf(temp_file,line);                        //复制数据
                    continue;
                }
            }
        else
            {
                line[strcspn(line, "\0")] = '\n';
                fprintf(temp_file,line);                        //复制数据
            }
    }
    fclose(file); 
    fclose(temp_file); 
    remove("room.ini");
    rename("temp.ini","room.ini");           //替换文件
    return 0;
}




//修改room字符的值
int data_change_char_room(char* input_title,char* input_key,char* input_data)
{
    char data[100];
    strcpy(data,input_data);
    char tmp_title[100];
    char line[1000];
    FILE*file=fopen("room.ini","r");
    FILE *temp_file = fopen("temp.ini", "w");       //创建临时文件
    fseek(file, 0, SEEK_SET);  
    while (fgets(line, sizeof(line), file))     //逐行读取到line
    {
        line[strcspn(line, "\n")] = '\0';    //去除换行符
        if(line[0] == '[' && line[strlen(line) - 1] == ']')     //找到[]
            {
                strncpy(tmp_title,line + 1,strlen(line) - 2);   //去除[];写入tmp_title
                tmp_title[strlen(line) - 2] = '\0';
                line[strcspn(line, "\0")] = '\n';
                fprintf(temp_file,line);
                continue;
            }
        if(strstr(line,input_key)!=NULL)
            {
                if(strcmp(tmp_title,input_title)==0)
                {
                    fprintf(temp_file,"%s=%s\n",input_key,data);        //写入修改后的数据
                    continue;
                }
                else 
                {
                    line[strcspn(line, "\0")] = '\n';
                    fprintf(temp_file,line);                    //复制数据
                    continue;
                }
            }
        else
            {
                line[strcspn(line, "\0")] = '\n';
                fprintf(temp_file,line);                        //复制数据
            }
    }
    fclose(file); 
    fclose(temp_file); 
    remove("room.ini");
    rename("temp.ini","room.ini");           //替换文件
    return 0;
}



#endif