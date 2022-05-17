#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int hidenp(char *param_1, char *param_2)
{
  int j = 0;
  for (size_t i = 0; param_2[i]; i++)
  {
    if (!param_1[j])
    {
      return 1;
    }
    if (param_1[j] == param_2[i])
    {
      j++;
    }
  }
  return 0;
}

int main(int argc, char const *argv[])
{
  printf("%d\n", hidenp("fgex.;", "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6"));
  printf("%d\n", hidenp("abc", "btarc"));
  printf("%d\n", hidenp("", "long string ?ddl"));
  return 0;
}
