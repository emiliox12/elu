#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int is_anagram(char *param_1, char *param_2)
{
  int charsArray[256] = {0};
  for (size_t i = 0; param_1[i]; i++)
  {
    charsArray[param_1[i]]++;
  }
  for (size_t i = 0; param_2[i]; i++)
  {
    charsArray[param_2[i]]--;
  }
  for (int i = 0; i < 256; i++)
  {
    printf("%d", charsArray[i]);
    if (charsArray[i] != 0)
    {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char const *argv[])
{
  printf("\n%d\n", is_anagram("ad", "bc"));
  return 0;
}
