#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Created one-way linked list as said in the tips
typedef struct List {
  char *data;
  struct List *next;
} List;

int main(int argc, char *argv[]) {
  FILE *in = NULL, *out = NULL; //initializations
  in = stdin;
  out = stdout;
  List *head = NULL;
  char *line = NULL;
  size_t size = 0;

  //Check if there is 3 arguments given in the command line parameter
  if (argc == 3) { 
    // Check if the files are same
    if (strcmp(argv[1],argv[2]) == 0) {
      fprintf(stderr, "error: input and output file must differ\n");
      exit(1);
    }
    //Check if the readable file is openable / exists
    if ((in = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
      exit(1);
    }
    //Check if the writable file is openable / exists
    if ((out = fopen(argv[2], "w")) == NULL) {
      fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);
      exit(1);
    }
    //Check if there is 2 arguments given in the command line parameter
  } else if (argc == 2) {
    //Check if the readable file is openable / exists
    if ((in = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
      exit(1);
    }  
    //Check if there is more tan 3 arguments or none given in the command line parameter
  } else if (argc > 3 || argc == 1) {
    fprintf(stderr, "usage: reverse <input> <output>\n");
    exit(1);
  }

  // While line doesn't return -1 aka error that the line is not readable
  while (getline(&line, &size, in) != -1) {
    List *node = malloc(sizeof(List)); // Create a new node
    if (node == NULL) { 
      free(line);
      fprintf(stderr, "error: malloc failed\n");
      exit(1);
    }
    // Put the line in the node's data and check it's not null
    if ((node->data = strdup(line)) == NULL) {
      free(line);
      fprintf(stderr, "error: strdup failed\n");
      exit(1);
    }
    // Nodes are added to the linked list in reverse
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
