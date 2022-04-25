#include <stdio.h>

int my_iterative_pow(int base, int power)
{
  if (power < 1)
  {
    return 0;
  }
  int res = base;
  for (int i = 1; i < power; i++)
  {
    res = res * base;
  }
  return res;
}

int main(int argc, char const *argv[])
{
  printf("27: %d\n", my_iterative_pow(3, 3));
  printf("256: %d\n", my_iterative_pow(2, 8));
  printf("25: %d\n", my_iterative_pow(5, 2));
  printf("64: %d\n", my_iterative_pow(4, 3));
  return 0;
}
