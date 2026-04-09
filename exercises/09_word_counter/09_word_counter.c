#include <stdio.h>
#include <stdbool.h>
#include <string.h> 
int main() {
    char str[]="Don't ask what your country can do for you, but ask what you can do for your country.";
    int wordCount = 0;
    bool canCount = false;
    int currentIdx = -1;
    for (int i =0;i<strlen(str);i++){
        char c = str[i];
        if (c>=65 && c<=90 || c>=97 && c<=122 || c=='\''){
            if(!canCount){
                wordCount++;
                canCount = true;
            }
        
        } else {
           canCount = false;
        }
    
    }



    printf("单词数量: %d\n", wordCount);
    
    return 0;
}