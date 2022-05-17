#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHAR_NUM 256

bool contains(char *string, char character)
{
  for (size_t i = 0; string[i]; i++)
  {
    if (string[i] == character)
    {
      return true;
    }
  }
  return false;
}

char *my_union(char *param_1, char *param_2)
{
  int str1Len = strlen(param_1);
  int str2Len = strlen(param_2);
  int maxLen = str1Len > str2Len ? str1Len : str2Len;
  int resLen = MAX_CHAR_NUM > maxLen ? MAX_CHAR_NUM : maxLen;
  char *res = malloc(sizeof(char) * resLen);
  int resCurrLen = 0;
  for (int i = 0; i < str1Len; i++)
  {
    char char1 = param_1[i];
    if (!contains(res, char1))
    {
      res[resCurrLen] = char1;
      resCurrLen++;
    }
  }
  for (int i = 0; i < str2Len; i++)
  {
    char char2 = param_2[i];
    if (!contains(res, char2))
    {
      res[resCurrLen] = char2;
      resCurrLen++;
    }
  }
  return res;
}

int main(int argc, char const *argv[])
{
  printf("%s\n", my_union("zpadinton", "paqefwtdjetyiytjneytjoeyjnejeyj"));
  printf("%s\n", "zpadintoqefwjy");
  return 0;
}
