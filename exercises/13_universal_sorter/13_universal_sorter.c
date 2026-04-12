#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*CompareFunc)(const void *, const void *);

int compareInt(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compareFloat(const void *a, const void *b) {
    float diff = (*(float*)a - *(float*)b);
    return (diff > 0) ? 1 : ((diff < 0) ? -1 : 0);
}

int compareString(const void *a, const void *b) {
    return strcmp(*(char**)a, *(char**)b);
}

void sort(void *array, size_t n, size_t size, CompareFunc compare) {
    qsort(array, n, size, compare);
}

void processFile(const char *filename) {
    FILE *fin = fopen(filename, "r");
    if (!fin) return;
    int choice, n;
    fscanf(fin, "%d", &choice);
    fscanf(fin, "%d", &n);

    if (n > 20) n = 20;  // 最多支持20个元素


    switch (choice) {
        // TODO: 在这里添加你的代码
        case 1: {
            int arr[n];
            for (int i = 0; i < n; i++) {
                if (fscanf(fin, "%d", &arr[i]) != 1) {
                    printf("错误: 文件 格式不正确\n");
                    fclose(fin);
                    return;
                }   
            }        
            sort(arr, n, sizeof(int), compareInt);
            printf("排序结果: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        }
        case 2: {
            float arr[n];
            for (int i = 0; i < n; i++) {
                if (fscanf(fin, "%f", &arr[i]) != 1) {
                    printf("错误: 文件  格式不正确\n");
                    fclose(fin);
                    return;
                }   
            }        
            sort(arr, n, sizeof(float), compareFloat);
            
            for (int i = 0; i < n; i++) {
                printf("%.2f ", arr[i]);
            }
            printf("\n");
            break;
        }
        case 3: {
            char *arr[n];
            for (int i = 0; i < n; i++) {
                char str[100];
                if (fscanf(fin, "%s", str) != 1) {
                    printf("错误: 文件  格式不正确\n");
                    fclose(fin);
                    return;
                }
                arr[i] = malloc(strlen(str) + 1);
                strcpy(arr[i], str);
            }        
            sort(arr, n, sizeof(char*), compareString);
       
            for (int i = 0; i < n; i++) {
                printf("%s ", arr[i]);
                free(arr[i]);
            }
            printf("\n");
            break;
        }
        default:
            printf("错误: 文件 格式不正确\n");
           
            break;

    }

    
}

int main() {
    processFile("int_sort.txt");
    processFile("float_sort.txt");

    return 0;
}