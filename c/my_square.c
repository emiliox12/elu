#include <stdio.h>
#include <stdlib.h>

void my_square(int x, int y)
{
  for (int i = 0; i < y; i++)
  {
    for (int j = 0; j < x; j++)
    {
      if ((i == 0 || i == y - 1) && (j == 0 || j == x - 1))
      {
        printf("o");
      }
      else if (i == 0 || i == y - 1)
      {
        printf("-");
      }
      else if (j == 0 || j == x - 1)
      {
        printf("|");
      }
      else
      {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main(int ac, char **av)
{
  if (ac != 3)
  {
    return 0;
  }
  int x = atoi(av[1]);
  int y = atoi(av[2]);
  my_square(x, y);
  return 0;
}