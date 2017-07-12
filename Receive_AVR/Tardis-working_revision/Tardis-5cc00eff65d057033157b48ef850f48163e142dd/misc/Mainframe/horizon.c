#include "horizon.h"

char *line;
char **args;
int status;

int
main(int argc, char **argv)
{
  // Load config files, if any.

  // Run command loop.
  lsh_loop();

  // Perform any shutdown/cleanup.

  return 0;
}
