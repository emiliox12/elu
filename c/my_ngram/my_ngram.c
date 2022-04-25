#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_CHARS 128

void n_gram(char *string)
{
  int resultLen = 0;
  char *result = malloc(strlen(string) > MAX_CHARS ? strlen(string) : MAX_CHARS * sizeof(char));
  int *nums = malloc(strlen(string) > MAX_CHARS ? strlen(string) : MAX_CHARS * sizeof(int));
  for (int i = 0; i < strlen(string); i++)
  {
    bool found = false;
    char elem = string[i];
    if (elem == '\"')
    {
      continue;
    }
    for (int j = 0; j < strlen(string); j++)
    {
      char elem2 = result[j];
      if (!elem2)
      {
        break;
      }
      if (elem == elem2)
      {
        nums[j]++;
        found = true;
      }
    }
    if (!found)
    {
      result[resultLen] = elem;
      nums[resultLen] = 1;
      resultLen++;
    }
  }
  for (int i = 0; i < resultLen - 1; ++i)
  {
    for (int j = 0; j < resultLen - i - 1; ++j)
    {
      if (result[j] > result[j + 1])
      {
        char temp = result[j + 1];
        result[j + 1] = result[j];
        result[j] = temp;
        int temp2 = nums[j + 1];
        nums[j + 1] = nums[j];
        nums[j] = temp2;
      }
    }
  }
  for (int i = 0; i < resultLen; i++)
  {
    printf("%c:%d\n", result[i], nums[i]);
  }
  free(result);
  free(nums);
}

int main(int ac, char **av)
{
  int i = 1;
  int len = 0;
  while (av[i])
  {
    len += strlen(av[i]);
    i++;
  }
  char *string = malloc(sizeof(char) * len);
  i = 1;
  while (av[i])
  {
    strcat(string, av[i]);
    i++;
  }
  n_gram(string);
  return 0;
}