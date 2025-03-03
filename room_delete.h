#include <stdio.h>
#include <string.h>
#include "room_change.h"

int room_delete(char *input_title) {
    char tmp_title[100];
    char line[1000];
    FILE *file = fopen("room.ini", "r");
    FILE *temp_file = fopen("temp.ini", "w"); 
    int delete_mode = 0; // 标记删除模式
    while (fgets(line, sizeof(line), file))         // 逐行读取到line
    { 
        line[strcspn(line, "\n")] = '\0';                // 去除换行符
        if (line[0] == '[' && line[strlen(line) - 1] == ']') // 找到[]
        {
            strncpy(tmp_title, line + 1, strlen(line) - 2); // 去除[];写入tmp_title
            tmp_title[strlen(line) - 2] = '\0'; // 终止字符串
            if (strcmp(tmp_title, input_title) == 0) 
            {
                delete_mode = 1; // 标记删除模式
                continue; 
            } 
            else 
            {
                delete_mode = 0; 
            }
        }
        if (delete_mode)        // 如果在删除模式，检查是否需要继续删除数据
        {  
            if (line[0] == '[') 
            {
                delete_mode = 0; // 遇到下一个标题，退出删除模式
            }
            continue; 
        }
        fprintf(temp_file, "%s\n", line);       // 写入临时文件
    }
    fclose(file);
    fclose(temp_file);
    remove("room.ini");
    rename("temp.ini", "room.ini"); // 替换文件
    return 0;
}