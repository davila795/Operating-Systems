#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int N, n, reps;
  char *buff;
  FILE *in, *out;

  if (argc != 5)
    error(1, 0, "wrong parameters");

  N = atoi(argv[1]);
  reps = atoi(argv[2]);
  buff = malloc(N);
  if (buff == NULL)
    error(1, errno, "out of memory");

  out = fopen(argv[4], "w");
  if (out == NULL)
    error(1, errno, "opening output file");

  // makes reps copies of the input file
  while (reps--)
  {
    in = fopen(argv[3], "r");
    if (in == NULL)
      error(1, errno, "opening input file");

    while (!feof(in))
    {
      n = fread(buff, 1, N, in);
      if (ferror(in))
        error(1, errno, "reading input file");

      fwrite(buff, 1, n, out);
      if (ferror(out))
        error(1, errno, "writing output file");
    }

    fclose(in);
  }
  fclose(out);
  exit(0);
}
