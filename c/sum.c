
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  size_t len = 3;
  char* buf = malloc(len * sizeof(char));
  int read;

  int total = 0;
  while ((read = getline(&buf, &len, stdin)) != -1) {
    char *endptr = NULL;
    int n = strtol(buf, &endptr, 0);
    errno = 0;
    if ((n == LONG_MIN || n == LONG_MAX) && errno != 0) {
      perror("failed to parse number from line");
    }
    //printf("read %d\n", n);
    total += n;
  }

  free(buf);
  printf("%d\n", total);
  return 0;
}

/* vim: set ai sw=2 ts=2 expandtab: */
