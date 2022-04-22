#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(int count, int compare) {
  char str[2];
  str[0] = compare;
  fwrite(&count, 4, 1, stdout);
  fwrite(&str, 1, 1, stdout);
}

int main(int argc, char *argv[]) {
  int i;
  char buffer[2];
  int compare;
  int count = 0;
  
  if (argc <= 1) {
    printf("wzip: file1 [file2 ...]\n");
    exit(1);
  }
  else {
    for (i = 1; i < argc; i++) {
      FILE *fp = fopen (argv[i], "r");
      if (fp == NULL) {
        printf("wzip: cannot open file\n");
        exit(1);
      }
      while(fread(buffer, 1, 1, fp)) {
        if (compare == 3) {
          break;
        }
        if (buffer[0] == compare) {
          count++;
        }
        else {
          if (count != 0) {
            encode(count, compare);
          }
          count = 1;
          compare = buffer[0];
        }
        
      }
      fclose(fp);
    }
  
  }
  return 0;
}
