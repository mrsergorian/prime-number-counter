/*
 * MIT License
 *
 * Copyright (c) 2022 Andrey Syrbu
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void
usage (void)
{
  fprintf (stderr, "prime-number-counter 1.0.0\n");
  fprintf (stderr,
           "Usage: prime-number-counter count-from count-to output-file\n\n");
  fprintf (stderr, "  count-from - number to count from\n");
  fprintf (stderr, "  count-to - number to count to\n");
  fprintf (stderr, "  output-file - output file\n");
}

int
main (int argc, char **argv)
{
  if (argc != 4)
    {
      usage ();
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
