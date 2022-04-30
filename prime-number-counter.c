#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool
is_prime_number (unsigned long long n)
{
  for (unsigned long long i = 2; i <= n / 2; i++)
    {
      if (n % i == 0)
        return false;
    }
  return true;
}

int
main (int argc, char **argv)
{
  const char prime_numbers_file_name[18] = "prime-numbers.txt";

  FILE *prime_numbers_file = fopen (prime_numbers_file_name, "w");

  if (!prime_numbers_file)
    {
      fprintf (stderr, "prime-number-counter: error: could not open %s file\n",
               prime_numbers_file_name);
      return EXIT_FAILURE;
    }

  const unsigned long long count_from = 2;
  const unsigned long long count_to = 4000;

  for (unsigned long long i = count_from; i <= count_to; i++)
    {
      if (is_prime_number (i))
        fprintf (prime_numbers_file, "%llu\n", i);
    }

  fclose (prime_numbers_file);

  return EXIT_SUCCESS;
}
