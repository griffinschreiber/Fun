#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "front-end/lexer.h"
#include "front-end/parser.h"

char *file_contents(char *path) {
  FILE *file = fopen(path, "r");
  if (!file) {
    printf("Could not open file at %s\n", path);
    return NULL;
  }
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file);
  char *buffer = malloc(size + 1);
  if (!buffer) {
    printf("Could not allocate memory for buffer.\n");
    fclose(file);
    return NULL;
  }
  if (fread(buffer, 1, size, file) != size) {
    printf("Could not read all of file.\n");
    free(buffer);
    fclose(file);
    return NULL;
  }
  buffer[size] = '\0';
  fclose(file);
  return buffer;
}

void print_usage(char **argv) {
  printf("USAGE: %s program.fun\n", argv[0]);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    print_usage(argv);
    exit(0);
  }
  char *path = argv[1];
  char *code = file_contents(path);
  if (code) {
    printf("Contents of %s:\n---\n\"%s\"\n---\n", path, code);
    AbstractSyntaxTree ast = parse(code);
    
    free(code);
  }
  
  return 0;
}
