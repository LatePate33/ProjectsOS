#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  char str[150];
  int i = 1;
  
  // Check if no command-line arguments are passed
  while(argc != 1)
  {
    FILE *fp = fopen(argv[i], "r");
    // Check the file is openable
    if(fp == NULL)
    {
      printf("wcat: cannot open file\n");
      exit(1);
    }
    while(fgets(str, 150, fp)) // https://man7.org/linux/man-pages/man3/fgets.3p.html
    {
      printf("%s", str);
    }
    --argc; // -1 from the argc, if multiple files
    ++i; // +1 to open the next file
    fclose(fp);
  }
  
  return 0;
};
