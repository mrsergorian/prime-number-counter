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
  if (argc != 4)
    {
      /* TODO display help text here */
      return EXIT_FAILURE;
    }

  const unsigned long long count_from = atoi (argv[1]);
  const unsigned long long count_to = atoi (argv[2]);

  const char *prime_numbers_file_name = argv[3];

  FILE *prime_numbers_file = fopen (prime_numbers_file_name, "w");

  if (!prime_numbers_file)
    {
      fprintf (stderr, "prime-number-counter: error: could not open %s file\n",
               prime_numbers_file_name);
      return EXIT_FAILURE;
    }

  for (unsigned long long i = count_from; i <= count_to; i++)
    {
      if (is_prime_number (i))
        fprintf (prime_numbers_file, "%llu\n", i);
    }

  fclose (prime_numbers_file);

  return EXIT_SUCCESS;
}
