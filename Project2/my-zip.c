#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(int count, int compare) {
  char str[2]; // tried to test if the problem was with the mark being in int/ascii 
  str[0] = compare;
  fwrite(&count, 4, 1, stdout); // https://www.tutorialspoint.com/c_standard_library/c_function_fwrite.htm 
  fwrite(&str, 1, 1, stdout);
}

int main(int argc, char *argv[]) {
  int i;
  char buffer[2];
  int compare;
  int count = 0;
  
  // if no command-line arguments are passed 
  if (argc <= 1) {
    printf("wzip: file1 [file2 ...]\n");
    exit(1);
  }
  else {
    for (i = 1; i < argc; i++) { // multiple files
      FILE *fp = fopen (argv[i], "r");
      if (fp == NULL) {
        printf("wzip: cannot open file\n");
        exit(1);
      }
      while(fread(buffer, 1, 1, fp)) { // https://eur02.safelinks.protection.outlook.com/GetUrlReputation
        if (compare == 3) { // 3 = ETX, if we reach end of text, break
          break;
        }
        if (buffer[0] == compare) { // if the mark is same, add count
          count++;
        }
        else {
          if (count != 0) { // != 0, so it doesn't trigger the first time
            encode(count, compare);
          }
          count = 1; // if it came past everything, there is at least 1 mark
          compare = buffer[0]; // set the mark to compare, so we can compare the next mark to this previous one 
        }
        
      }
      fclose(fp);
    }
  
  }
  return 0;
}
