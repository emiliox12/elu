#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

int calcMaxStars(int baseInput)
{
  int starsNum = 1;
  int decrease = 2;
  for (size_t i = 0; i < baseInput; i++)
  {
    starsNum -= decrease;
    decrease += !(i % 2) ? 2 : 0;
    for (size_t j = 0; j < i + 4; j++)
    {
      starsNum += 2;
    }
  }
  return starsNum;
}

int printBase(int baseInput, int maxStars)
{
  int spacesNum = ((maxStars / 2) - baseInput / 2) + !(baseInput % 2);
  for (size_t i = 0; i < baseInput; i++)
  {
    for (size_t i = 0; i < spacesNum; i++)
    {
      printf(" ");
    }
    for (size_t i = 0; i < baseInput; i++)
    {
      printf("|");
    }
    printf("\n");
  }
}

void printTree(int baseInput)
{
  int maxStars = calcMaxStars(baseInput);
  int numLines = 0;
  int spacesNum = maxStars / 2;
  int starsNum = 1;
  int decrease = 2;
  for (size_t i = 0; i < baseInput; i++)
  {
    starsNum -= decrease;
    spacesNum += decrease / 2;
    decrease += !(i % 2) ? 2 : 0;
    for (size_t j = 0; j < i + 4; j++)
    {
      starsNum += 2;
      spacesNum -= 1;
      for (size_t i = 0; i < spacesNum; i++)
      {
        printf(" ");
      }
      for (size_t i = 0; i < starsNum; i++)
      {
        printf("*");
      }
      printf("\n");
    }
  }
  printBase(baseInput, maxStars);
}

int main(int argc, char const *argv[])
{
  int base = atoi(argv[1]);
  printTree(base);
  return 0;
}
