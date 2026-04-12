#include "myhash.h"
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trim(char *str) {
    int j = strlen(str) - 1;
    while (j >= 0 && isspace(str[j])) {
        str[j] = '\0';
        j--;
    }
    int i = 0;
    while(isspace(str[i])){
        i++;
    }
    
    if(i < strlen(str)){
      memmove(str,str+i,strlen(str+i)+1);
    } 
}

int load_dictionary(const char *filename, HashTable *table, uint64_t *dict_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("无法打开词典文件");
        return -1;
    }

    char line[1024];
    char current_word[100] = {0};
    char current_translation[1024] = {0};
    int in_entry = 0;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        trim(line);

        if (line[0] == '#') {
            in_entry = 1; // 表示当前行是一个有效的词典条目
            strncpy(current_word, line + 1, sizeof(current_word) - 1); // 复制 # 后面的内容为单词
            trim(current_word);
        } else if (strncmp(line, "Trans:", 6) == 0 && in_entry) {
            strncpy(current_translation, line + 6, sizeof(current_translation) - 1); // 复制 Trans: 后面的内容为译文
            trim(current_translation);
            // 插入哈希表
            if (hash_table_insert(table, current_word, current_translation) != 1) {
                fprintf(stderr, "插入字典条目失败: %s -> %s\n", current_word, current_translation);
                fclose(file);
                return -1;
            }
            // 增加字典计数
            (*dict_count)++;
            in_entry = 0; // 重置 in_entry 为 0，等待下一个 # 开头的行
        } 
    }

    fclose(file);
    return 0;
}
