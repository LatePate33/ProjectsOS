#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void argument_length(int arg)
{
  if(arg <= 1)
  {
    printf("wzip: file1 [file2 ...]\n");
    exit(1);
  }

}

void encode(char *str)
{
  int count;
  for(int j = 0; str[j]; j++)
  {
    if(str[j+1] != '\0')
    {
      count = 1;
      while(str[j] == str[j+1])
      {
        count++, j++;
      }
      fwrite(&count, sizeof(int), 1, stdout);
      fwrite(&str[j], 1, 1, stdout);
    }
  }
free(str);
}

int main(int argc, char *argv[])
{
  argument_length(argc);
  int i = 1;
  
  char buffer[2];
  
  while(argc != 1)
  {
    int count2 = 0;
    FILE *fp = fopen(argv[i], "rb");
    if(fp == NULL)
    {
      printf("wzip: cannot open file\n");
      exit(1);
    }
    //Count characters
    while(fread(buffer,1,1, fp) == 1)
    {
      ++count2;
    }
    char *str = malloc(sizeof(char) * count2);
    rewind(fp);
    //Read characters into to a string
    while(fread(buffer, 1, 1, fp) == 1)
    {
      strncat(str, buffer, 1);
    }
    printf("%s\n", str);
    encode(str);
    --argc;
    ++i;
    fclose(fp);
  }
  
  return 0;
}
