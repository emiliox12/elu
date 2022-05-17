#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
  int size;
  char **array;
} string_array;
#endif

string_array *my_split(char *param_1, char *param_2)
{
  char *array[] = {};
  int size = 0;
  int start = 0;
  for (size_t i = 0; param_1[i]; i++)
  {
    if (param_1[i] == param_2[0])
    {
      size_t j = 0;
      for (; param_2[j]; j++)
      {
        if (param_1[i] != param_2[0])
        {
          break;
        }
      }
      if (j == strlen(param_2))
      {
        char res[i - start];
        size_t k = 0;
        for (; k < i; k++)
        {
          res[k] = param_1[start + k];
        }
        res[k] = '\0';
        array[size] = malloc(sizeof(char) * strlen(res));
        strcpy(array[size], res);
        start = i + j;
        size++;
      }
    }
  }
  char res[start - strlen(param_1)];
  size_t k = 0;
  for (; k < strlen(param_1); k++)
  {
    res[k] = param_1[start + k];
  }
  res[k] = '\0';
  printf("res: %s, size: %d\n", res, size);
  /* array[size] = malloc(sizeof(char) * strlen(res));
  strcpy(array[size], res);
  size++; */
  string_array *strArray = (string_array *)malloc(sizeof(string_array));
  strArray->array = array;
  strArray->size = size;
  return strArray;
}
int main(int argc, char const *argv[])
{
  string_array *res = my_split("abc def gh-!", "-");
  printf("size: %d\n", res->size);
  for (size_t i = 0; i < res->size; i++)
  {
    printf("arr[%ld]: %s\n", i, res->array[i]);
  }

  return 0;
}
