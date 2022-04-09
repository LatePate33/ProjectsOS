#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  char str[150];
  int i = 1;
  
  while(argc != 1)
  {
    FILE *fp = fopen(argv[i], "r");
    if(fp == NULL)
    {
      printf("wcat: cannot open file\n");
      exit(1);
    }
    while(fgets(str, 150, fp))
    {
      printf("%s", str);
    }
    --argc;
    ++i;
    fclose(fp);
  }
  
  return 0;
};
