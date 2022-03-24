#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
  int size;
  char **array;
} string_array;
#endif

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
  int size;
  int *array;
} integer_array;
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

integer_array *my_count_on_it(string_array *strArray)
{
  integer_array *intArray = malloc(100);
  intArray->array = malloc(sizeof(int) * strArray->size);
  for (int i = 0; i < strArray->size; i++)
  {
    intArray->array[i] = strlen(strArray->array[i]);
  }
  intArray->size = strArray->size;
  return intArray;
}

int main()
{
  char *array[] = {"This", "is", "the", "way"};
  string_array strArray = {
      .array = array,
      .size = 4,
  };
  integer_array *res = my_count_on_it(&strArray);
  for (int i = 0; i < res->size; i++)
  {
    printf("%d\n", res->array[i]);
  }

  return 0;
}