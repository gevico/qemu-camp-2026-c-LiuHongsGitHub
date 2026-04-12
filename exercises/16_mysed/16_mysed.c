#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

int parse_replace_command(const char* cmd, char** old_str, char** new_str) {
    if (cmd[0] != 's' || cmd[1] != '/') {
        return -1;
    }
    const char* first_slash = strchr(cmd, '/');
    const char* second_slash = strchr(first_slash + 1, '/');
    if (second_slash == NULL) {
        return -1;
    }
    *old_str = strndup(first_slash + 1, second_slash - first_slash - 1);
    const char* third_slash = strchr(second_slash + 1, '/');
    if (third_slash == NULL) {
        return -1;
    }
    *new_str = strndup(second_slash + 1, third_slash - second_slash - 1);   
    

    return 0;
}

void replace_first_occurrence(char* str, const char* old, const char* new) {
    // TODO: 在这里添加你的代码
    char* pos = strstr(str, old);
    if (pos!= NULL) {
        int old_len = strlen(old);
        int new_len = strlen(new);
        int suffix_len = strlen(pos+old_len);
        memmove(pos + new_len, pos + old_len, suffix_len + 1);
        memcpy(pos, new, new_len);
    }

}

int main(int argc, char* argv[]) {
    const char* replcae_rules = "s/unix/linux/";

    char line[MAX_LINE_LENGTH] = {"unix is opensource. unix is free os."};

    char* old_str = NULL;
    char* new_str = NULL;
    
    if (parse_replace_command(replcae_rules, &old_str, &new_str) != 0) {
        fprintf(stderr, "Invalid replace command format. Use 's/old/new/'\n");
        return 1;
    }

    
    replace_first_occurrence(line, old_str, new_str);
    fputs(line, stdout);

    free(old_str);
    free(new_str);
    return 0;
}
