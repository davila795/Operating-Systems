#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define LIMIT 20

struct fact_entry
{ /* Definition of each table entry */
  int n;
  long long int lli_fact; /* 64-bit integer */
  char *str_fact;
};

void panic(char *m)
{
  fprintf(stderr, "%s\n", m);
  exit(0);
}

long long int factorial(int n)
{
  if (n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}

int main(int argc, char *argv[])
{
  int n;
  int i;
  struct fact_entry *fact_table;

  if (argc != 2)
    panic("wrong parameters");

  n = atoi(argv[1]);
  if (n < 0)
    panic("n too small");
  if (n > LIMIT)
    panic("n too big");

  /* Your code starts here */
  // Allocate memory
  fact_table = (struct fact_entry *)malloc((n + 1) * sizeof(struct fact_entry));

  if (!fact_table)
    panic("Error allocating memory for fact_table");

  // Compute fact(n) for i=0 to n
  for (i = 0; i <= n; i++)
  {
    fact_table[i].n = i;
    fact_table[i].lli_fact = factorial(i);

    int number_of_digits = floor(log10(fact_table[i].lli_fact)) + 1;

    fact_table[i].str_fact = (char *)malloc((number_of_digits + 1) * sizeof(char));

    if (!fact_table[i].str_fact)
      panic("Error allocating memory for fact_table[i].str_fact");

    sprintf(fact_table[i].str_fact, "%lld", fact_table[i].lli_fact);
  }
  /* Your code ends here */

  // print computed numbers
  for (i = 0; i <= n; i++)
  {
    printf("%d %lld %s\n", fact_table[i].n, fact_table[i].lli_fact,
           fact_table[i].str_fact);
  }

  /* Your code starts here */
  // Free memory
  for (i = 0; i <= n; i++)
  {
    free(fact_table[i].str_fact);
  }

  free(fact_table);
  /* Your code ends here */

  return 0;
}
