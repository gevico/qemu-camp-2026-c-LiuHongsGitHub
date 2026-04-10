#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_elf_type(uint16_t e_type) {
  const char *type_str;
  switch (e_type) {
    case ET_REL:
      type_str = "Relocatable file (.o)";
      break;
    case ET_EXEC:
      type_str = "Executable file";
      break;
    case ET_DYN:
      type_str = "Shared object / PIE";
      break;
    case ET_CORE:
      type_str = "Core file";
      break;
    default:
      type_str = "Unknown type";
      break;
  }
  printf("ELF Type: %s (0x%x)\n", type_str, e_type);
}

int main(int argc, char *argv[]) {
  char filepath[2][256] = {
    "./17_myfile.o",
    "./17_myfile",
  };
  int len =sizeof(filepath)/sizeof(filepath[0]);

  int fd;
  Elf64_Ehdr ehdr;

  // TODO: 在这里添加你的代码
  for (int i = 0; i < len; i++) {
    fd = open(filepath[i], O_RDONLY);
    if (fd < 0) {
      perror("open");
      exit(1);
    }
    read(fd,&ehdr,sizeof(ehdr));
    if 
    print_elf_type(ehdr.e_type);
    close(fd);
  }
  return 0;
}
