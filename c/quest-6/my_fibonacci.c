#include <stdio.h>

int my_fibonacci(int fibonacci)
{
  if (fibonacci < 0)
  {
    return -1;
  }
  else if (fibonacci <= 1)
  {
    return fibonacci;
  }
  else
  {
    return my_fibonacci(fibonacci - 1) + my_fibonacci(fibonacci - 2);
  }
}

int main(int argc, char const *argv[])
{
  printf("1: %d\n", my_fibonacci(1));
  printf("1: %d\n", my_fibonacci(2));
  printf("2: %d\n", my_fibonacci(3));
  printf("3: %d\n", my_fibonacci(4));
  return 0;
}
