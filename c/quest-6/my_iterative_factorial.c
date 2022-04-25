#include <stdio.h>

int my_iterative_factorial(int factorial)
{
  int res = factorial;
  for (int i = factorial - 1; i > 0; i--)
  {
    res = res * i;
  }
  return res;
}

int main(int argc, char const *argv[])
{
  printf("24: %d\n", my_iterative_factorial(4));
  printf("120: %d\n", my_iterative_factorial(5));
  printf("720: %d\n", my_iterative_factorial(6));
  printf("5040: %d\n", my_iterative_factorial(7));
  return 0;
}
