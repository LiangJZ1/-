#include <stdio.h>
#include <string.h>
#include "room_change.h"

int room_delete(char *input_title) {
    char tmp_title[100];
    char line[1000];
    FILE *file = fopen("room.ini", "r");
    FILE *temp_file = fopen("temp.ini", "w"); 
    int delete_mode = 0; // ���ɾ��ģʽ
    while (fgets(line, sizeof(line), file))         // ���ж�ȡ��line
    { 
        line[strcspn(line, "\n")] = '\0';                // ȥ�����з�
        if (line[0] == '[' && line[strlen(line) - 1] == ']') // �ҵ�[]
        {
            strncpy(tmp_title, line + 1, strlen(line) - 2); // ȥ��[];д��tmp_title
            tmp_title[strlen(line) - 2] = '\0'; // ��ֹ�ַ���
            if (strcmp(tmp_title, input_title) == 0) 
            {
                delete_mode = 1; // ���ɾ��ģʽ
                continue; 
            } 
            else 
            {
                delete_mode = 0; 
            }
        }
        if (delete_mode)        // �����ɾ��ģʽ������Ƿ���Ҫ����ɾ������
        {  
            if (line[0] == '[') 
            {
                delete_mode = 0; // ������һ�����⣬�˳�ɾ��ģʽ
            }
            continue; 
        }
        fprintf(temp_file, "%s\n", line);       // д����ʱ�ļ�
    }
    fclose(file);
    fclose(temp_file);
    remove("room.ini");
    rename("temp.ini", "room.ini"); // �滻�ļ�
    return 0;
}