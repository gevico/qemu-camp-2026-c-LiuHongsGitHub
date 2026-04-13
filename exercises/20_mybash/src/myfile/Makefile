# src/myfile/Makefile

CC = gcc
CFLAGS = -Wall -I../../include -g -fPIE

# 库名称
LIBNAME := myfile
# 静态库输出名：libmyfile.a
LIB := lib$(LIBNAME).a
# 最终库输出目录（比如 ./obj/src/myfile/）
OBJDIR ?= ./obj
# 最终 .a 文件路径
LIB_PATH := $(OBJDIR)/$(LIB)

# 源文件
SRCS := myfile.c
OBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

all: $(LIB_PATH)

$(OBJDIR): 
	mkdir -p $(OBJDIR)
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(LIB_PATH): $(OBJS)
	ar rcs $@ $(OBJS)

clean:
	$(RM) -r $(OBJDIR)