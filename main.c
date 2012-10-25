#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

// Build with : clang main.c -lgmp

// ret is the big number to modify, n is the factiorial to compute
void factorial(mpz_t ret, unsigned long int n)
{     
  mpz_t result;
  mpz_init(result);
  mpz_set_d(result, 1);

  mpz_t i;
  mpz_init(i);
  mpz_set_d(i, 2);

  for(; mpz_cmp_ui(i,n) <= 0;  mpz_add_ui(i,i,1)){
    mpz_mul(result, result, i);
  }

  mpz_set(ret, result);
  return;
}

int main(int argc, char const *argv[])
{

  if (argc != 2)
  {
    fprintf (stderr, "Usage: factorial $number\n");
    return 1;
  }

  mpz_t ret;
  mpz_init(ret);
  factorial(ret,atoi(argv[1]));
  mpz_out_str(stdout, 10, ret);
  return 0;
}