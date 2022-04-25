#include <stdio.h>

int my_recursive_factorial(int factorial)
{
  if (factorial < 1)
  {
    return 0;
  }
  else if (factorial == 1)
  {
    return factorial;
  }
  else
  {
    return factorial * my_recursive_factorial(factorial - 1);
  }
}

int main(int argc, char const *argv[])
{
  printf("24: %d\n", my_recursive_factorial(4));
  printf("120: %d\n", my_recursive_factorial(5));
  printf("720: %d\n", my_recursive_factorial(6));
  printf("5040: %d\n", my_recursive_factorial(7));
  return 0;
}
