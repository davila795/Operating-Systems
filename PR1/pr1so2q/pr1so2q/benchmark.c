#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>

int main(int argc, char *argv[])
{
  int N, in, out, n, reps;
  char *buff;

  if (argc != 5)
    error(1, 0, "wrong parameters");

  N = atoi(argv[1]);
  reps = atoi(argv[2]);
  buff = malloc(N);
  if (buff == NULL)
    error(1, errno, "out of memory");

  out = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0600);
  if (out < 0)
    error(1, errno, "opening output file");

  // makes reps copies of the input file
  while (reps--)
  {
    in = open(argv[3], O_RDONLY);
    if (in < 0)
      error(1, errno, "opening input file");

    while ((n = read(in, buff, N)) > 0)
      if (write(out, buff, n) < 0)
        error(1, errno, "writing output file");

    if (n < 0)
      error(1, errno, "reading input file");
    close(in);
  }
  close(out);
  exit(0);
}
