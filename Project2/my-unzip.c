#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  char buffer[5];
  int i,j;
  
  if (argc <= 1) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }
  for(i = 1; i<argc; i++){
    FILE *fp = fopen(argv[i], "rb");
    if(fp == NULL){
      printf("wunzip: cannot open file\n");
      exit(1);
    }
  while(fread(buffer, 4, 1, fp)){
    //put the read buffer into count so we can use same buffer to read characters
    int count = *buffer;
    //set buffer empty
    memset(buffer, 0, strlen(buffer));
    fread(buffer, 1, 1, fp);
    for(j = 0; j < count; j++){
      printf("%s", buffer);
    
    }
  
  };
  fclose(fp);
  }

return 0;

};
