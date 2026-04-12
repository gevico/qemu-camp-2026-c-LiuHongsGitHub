CC = gcc
CFLAGS = -Wall -g -O2 -fPIE

TARGET := 17_myfile
SRCS := 17_myfile.c
OBJS := $(SRCS:.c=.o)

all: $(TARGET)

# TODO: 在这里添加你的代码

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 生成 .o 目标文件（自动推导规则）
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean