#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>

#ifdef TODO

#define DEBUG_PRINT(fmt, ...) \
    do { \
        if (getenv("DEBUG_LEVEL")) { \
            int level = atoi(getenv("DEBUG_LEVEL")); \
            if (level == 2) { \
                fprintf(stderr, "DEBUG: func=%s, line=%d, " fmt "\n", __func__, __LINE__, ##__VA_ARGS__); \
            } else if (level == 3) { \
                fprintf(stderr, "DEBUG: func=%s, line=%d\n", __func__, __LINE__); \
                void *array[10]; \
                size_t size; \
                char **strings; \
                size = backtrace(array, 10); \
                strings = backtrace_symbols(array, size); \
                if (strings != NULL) { \
                    fprintf(stderr, "Backtrace:\n"); \
                    for (size_t i = 0; i < size; i++) { \
                        fprintf(stderr, "  %s\n", strings[i]); \
                    } \
                    free(strings); \
                } \
            } \
        } \
    } while (0)

#else

#define DEBUG_PRINT(fmt, ...) do {} while (0)

#endif

