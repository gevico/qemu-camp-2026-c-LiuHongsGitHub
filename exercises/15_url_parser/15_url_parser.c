#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/**
 * URL参数解析器
 * 输入：包含http/https超链接的字符串
 * 输出：解析出所有的key-value键值对，每行显示一个
 */

int parse_url(const char* url) {
    int err = 0;
    int i =0;
    while(url[i] != '\0'&& url[i] != '?' ){
        i++;
    }
    if (url[i] == '\0') {
        return -1;
    }
    i++; 
    while (url[i] != '\0') {
        char key[100] = {0};
        char val[100] = {0};
        int k = 0;
        while (url[i]!= '=' &&url[i] != '\0')
        {
            key[k++] = url[i++];
        }
        key[k] = '\0';
        i++;
        int v = 0;
        while (url[i] != '&' &&url[i] != '\0')
        {
            val[v++] = url[i++];
        }
        val[v] = '\0';
        printf("key = %s, value = %s\n", key, val);
        
        if (url[i] == '&') {
            i++;
        }


    }

exit:
    return err;
}

int main() {
    const char* test_url = "https://cn.bing.com/search?name=John&age=30&city=New+York";

    printf("Parsing URL: %s\n", test_url);
    printf("Parameters:\n");

    parse_url(test_url);

    return 0;
}