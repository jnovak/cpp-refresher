
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

int main(int argc, char** argv) {

  GIOChannel *chan = NULL;
  GString *line = NULL;
  GIOStatus status;
  GError *err = NULL;

  chan = g_io_channel_unix_new(fileno(stdin));
  line = g_string_sized_new(32);

  int total = 0;
  while ((status = g_io_channel_read_line_string(chan, line, NULL, & err)) == G_IO_STATUS_NORMAL) {
    char *endptr = NULL;
    int n = strtol(line->str, &endptr, 0);
    errno = 0;
    if ((n == LONG_MIN || n == LONG_MAX) && errno != 0) {
      perror("failed to parse number from line");
    }
    total += n;
  }

  g_io_channel_shutdown(chan, FALSE, &err);
  g_io_channel_unref(chan);
  g_string_free(line, TRUE);

  if (err != NULL) {
    g_error_free(err);
  }

  printf("%d\n", total);
  return 0;
}

/* vim: set ai sw=2 ts=2 expandtab: */
