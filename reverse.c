#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List {
  char *data;
  struct List *next;
} List;

int main(int argc, char *argv[]) {
  FILE *in = NULL, *out = NULL;
  in = stdin;
  out = stdout;
  List *head = NULL;
  char *line = NULL;
  size_t size = 0;

  if (argc == 3) {
    if (strcmp(argv[1],argv[2]) == 0) {
      fprintf(stderr, "error: input and output file must differ\n");
      exit(1);
    }
    if ((in = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
      exit(1);
    }
    if ((out = fopen(argv[2], "w")) == NULL) {
      fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);
      exit(1);
    }
  } else if (argc == 2) {
    if ((in = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
      exit(1);
    }  
  } else if (argc > 3 || argc == 1) {
    fprintf(stderr, "usage: reverse <input> <output>\n");
    exit(1);
  }

  while (getline(&line, &size, in) != -1) {
    List *node = malloc(sizeof(List));
    if (node == NULL) {
      free(line);
      fprintf(stderr, "error: malloc failed\n");
      exit(1);
    }
    if ((node->data = strdup(line)) == NULL) {
      free(line);
      fprintf(stderr, "error: strdup failed\n");
      exit(1);
    }
    node->next = head;
    head = node;
  }

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
