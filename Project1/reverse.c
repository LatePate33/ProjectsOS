#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// https://www.geeksforgeeks.org/linked-list-set-1-introduction/
// Created one-way linked list as said in the tips
typedef struct List {
  char *data;
  struct List *next;
} List;

// https://www.tutorialspoint.com/cprogramming/c_file_io.htm
int main(int argc, char *argv[]) {
  FILE *in = NULL, *out = NULL; // initializations
  in = stdin;
  out = stdout;
  List *head = NULL;
  char *line = NULL;
  // https://www.geeksforgeeks.org/size_t-data-type-c-language/
  size_t size = 0;

  // Check if there is 3 arguments given in the command line parameter
  if (argc == 3) { 
    // Check if the files are same
    //https://www.programiz.com/c-programming/library-function/string.h/strcmp
    if (strcmp(argv[1],argv[2]) == 0) {
      fprintf(stderr, "reverse: input and output file must differ\n");
      exit(1);
    }
    // Check if the readable file is openable / exists
    if ((in = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
      exit(1);
    }
    // Check if the writable file is openable / exists
    if ((out = fopen(argv[2], "w")) == NULL) {
      fprintf(stderr, "reverse: cannot open file '%s'\n", argv[2]);
      exit(1);
    }
    // Check if there is 2 arguments given in the command line parameter
  } else if (argc == 2) {
    //Check if the readable file is openable / exists
    if ((in = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
      exit(1);
    }  
    // Check if there is more than 3 arguments
  } else if (argc > 3 ) {
    fprintf(stderr, "usage: reverse <input> <output>\n");
    exit(1);
  }

  //https://c-for-dummies.com/blog/?p=1112
  // While line doesn't return -1 aka error that the line is not readable
  //https://man7.org/linux/man-pages/man3/getline.3.html
  while (getline(&line, &size, in) != -1) {
    List *node = malloc(sizeof(List)); // Create a new node
    if (node == NULL) { 
      free(line);
      fprintf(stderr, "error: malloc failed\n");
      exit(1);
    }
    // Put the line in the node's data and check it's not null
    // https://www.geeksforgeeks.org/strdup-strdndup-functions-c/
    if ((node->data = strdup(line)) == NULL) {
      free(line);
      fprintf(stderr, "error: strdup failed\n");
      exit(1);
    }
    // Nodes are added to the linked list in reverse
    //https://www.log2base2.com/data-structures/linked-list/inserting-a-node-at-the-end-of-a-linked-list.html
    node->next = head; 
    head = node;
  }

  // Linked list is read to the stdout
  while (head != NULL) {
    List *temp = head;
    fprintf(out, "%s", head->data);
    head = head->next;
    free(temp->data);
    free(temp);
  }

  free(line);
  fclose(in);
  fclose(out);
  return 0;
}
