#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  char *line = NULL;
  size_t len = 0;
  
  // if no commandline-line arguments are passed
  if (argc <= 1) {
    printf("wgrep: searchterm [file ...]\n");
    exit(1);
  }
  // if no file is passed
  if (argc == 2) {
    FILE *fp = stdin; // reading from standard input
    while (getline(&line, &len, fp) != -1) { // https://man7.org/linux/man-pages/man3/getline.3.html
      if (strstr(line, argv[1])) { // https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm 
        printf("%s", line); // if the sequence matches, we print the whole line
      }
    }
    free(line);
    fclose(fp);
  }
  else {
    FILE *fp = fopen(argv[2], "r");
    // check the file is openable
    if (fp == NULL) {
      printf("wgrep: cannot open file\n");
      exit(1);
    }
    while (getline(&line, &len, fp) != -1) { // https://man7.org/linux/man-pages/man3/getline.3.html
      if (strstr(line, argv[1])) { // https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm 
        printf("%s", line); // if the sequence matches, we print the whole line
      }
    }
    free(line);
    fclose(fp);
  }
  
  return 0;
}
