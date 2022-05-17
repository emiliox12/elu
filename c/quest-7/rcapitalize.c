#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHAR_NUM 256

bool isLower(char elem)
{
  return elem > 96 && elem < 123;
}

bool isUpper(char elem)
{
  return elem > 64 && elem < 91;
}

int toUpper(int elem)
{
  return isLower(elem) ? elem - 32 : elem;
}

int toLower(int elem)
{
  return isUpper(elem) ? elem + 32 : elem;
}

char *rcapitalize(char *param_1)
{
  int i = 0;
  for (; param_1[i]; i++)
  {
    if (param_1[i] == ' ')
    {
      param_1[i - 1] = toUpper(param_1[i - 1]);
    }
    else
    {
      param_1[i] = toLower(param_1[i]);
    }
  }
  param_1[i - 1] = toUpper(param_1[i - 1]);
  return param_1;
}

int main(int argc, char const *argv[])
{
  char *test = malloc(100);
  strcpy(test, "a FiRSt LiTTlE TESt");
  printf("%s\n", "a FiRSt LiTTlE TESt");
  printf("%s\n", rcapitalize(test));
  printf("%s\n", "A firsT littlE tesT");
  return 0;
}
