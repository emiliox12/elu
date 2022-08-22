#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char *my_strip(char *param_1)
{
  bool remove = true;
  char *res = malloc(sizeof(char) * strlen(param_1));
  int resPos = 0;
  size_t i = 0;
  for (; param_1[i]; i++)
  {
    if (param_1[i] == ' ' || param_1[i] == '\t')
    {
      if (remove)
      {
        continue;
      }
      else
      {
        remove = true;
        res[resPos] = param_1[i];
        resPos++;
      }
    }
    else
    {
      remove = false;
      res[resPos] = param_1[i];
      resPos++;
    }
  }
  resPos--;
  while (res[resPos] == ' ' || res[resPos] == '\t')
  {
    resPos--;
  }
  res[resPos + 1] = '\0';
  return res;
}

int main(int argc, char const *argv[])
{
  printf("*%s*\n", my_strip("No  S***    Sherlock..."));
  printf("*%s*\n", my_strip("See? It's easy to print the same thing"));
  printf("*%s*\n", my_strip(" this        time it      will     be    more complex  . "));
  return 0;
}
