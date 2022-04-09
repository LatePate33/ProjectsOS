#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  char *line = NULL;
  size_t len = 0;
  
  
  if (argc <= 1) {
    printf("wgrep: searchterm [file ...]\n");
    exit(1);
  }
  if (argc == 2) {
    FILE *fp = stdin;
    while (getline(&line, &len, fp) != -1) {
      if (strstr(line, argv[1])) {
        printf("%s", line);
      }
    }
    free(line);
    fclose(fp);
  }
  else {
    FILE *fp = fopen(argv[2], "r");
    if (fp == NULL) {
      printf("wgrep: cannot open file\n");
      exit(1);
    }
    while (getline(&line, &len, fp) != -1) {
      if (strstr(line, argv[1])) {
        printf("%s", line);
      }
    }
    free(line);
    fclose(fp);
  }
  
  return 0;
}
