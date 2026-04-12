CC = gcc
CFLAGS = -Wall -g -O2

TARGET := 16_mysed
SRCS := 16_mysed.c
OBJS := $(SRCS:.c=.o)

all: $(TARGET)

# TODO: 在这里添加你的代码
# I AM NOT DONE
$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.O: %.C
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean