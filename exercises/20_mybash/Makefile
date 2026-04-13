# =============================================
# 主 Makefile
# 功能：
#   - mybash：生成二进制，放到 bin/
#   - 其他模块（mysed, myfile, mywc, mytrans）：生成静态库 .a，放到 obj/xxx/，.o 放到 obj/xxx/（或 out/，但建议统一）
#   - 所有子模块 Makefile 应支持 OBJDIR 和 BINDIR 参数
# =============================================

PWD := $(shell pwd)

SUBDIRS := mysed myfile mywc mytrans

all: mybash

$(SUBDIRS):
	$(MAKE) -s -C src/$@ OBJDIR=$(PWD)/obj/$@

mybash: $(SUBDIRS)
	$(MAKE) -s -C src/mybash BINDIR=$(PWD)/bin OBJDIR=$(PWD)/obj/mybash LINKLIBS="-L$(PWD)/obj/mysed -L$(PWD)/obj/myfile -L$(PWD)/obj/mywc -L$(PWD)/obj/mytrans"

clean:
	$(MAKE) -s -C src/mybash clean BINDIR=$(PWD)/bin OBJDIR=$(PWD)/obj/mybash
	$(MAKE) -s -C src/mysed clean OBJDIR=$(PWD)/obj/mysed
	$(MAKE) -s -C src/myfile clean OBJDIR=$(PWD)/obj/myfile
	$(MAKE) -s -C src/mywc clean OBJDIR=$(PWD)/obj/mywc
	$(MAKE) -s -C src/mytrans clean OBJDIR=$(PWD)/obj/mytrans
	$(RM) -r $(PWD)/obj $(PWD)/bin

.PHONY: all $(SUBDIRS) mybash clean