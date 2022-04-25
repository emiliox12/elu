#include <stdio.h>

int my_recursive_pow(int base, int power)
{
  if (power < 1)
  {
    return 0;
  }
  else if (power == 1)
  {
    return base;
  }
  else
  {
    return base * my_recursive_pow(base, power - 1);
  }
}

int main(int argc, char const *argv[])
{
  printf("1000: %d\n", my_recursive_pow(10, 3));
  printf("256: %d\n", my_recursive_pow(2, 8));
  printf("25: %d\n", my_recursive_pow(5, 2));
  printf("64: %d\n", my_recursive_pow(4, 3));
  return 0;
}
