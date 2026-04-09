#include <stdio.h>
#include <stdlib.h>

int main() {
    char source[] = "Hello, World! This is a test string for my_strcpy function.\n";
    
    char *destination;
    destination = (char *)malloc((strlen(source)+1)*sizeof(char));
    if (destination == NULL) {
        printf("内存分配失败！\n");
        return -1;
    }
    for (int i = 0; source[i]!= '\0'; i++) {
        destination[i] = source[i];
    }
    destination[strlen(source)] = '\0';
    printf("拷贝后的字符串: %s", destination);
    free(destination);
    return 0;
}