#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
  int size;
  char **array;
} string_array;
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *my_join(string_array *strArray, char *separator)
{
  int resLength = 0;
  int separatorLen = strlen(separator);
  for (int i = 0; i < strArray->size; i++)
  {
    resLength += strlen(strArray->array[i]) + separatorLen;
  }
  char *resString = malloc(resLength);
  for (int i = 0; i < strArray->size; i++)
  {
    char *separatedString = malloc(strlen(strArray->array[i]) + separatorLen);
    strcat(separatedString, strArray->array[i]);
    strcat(separatedString, separator);
    strcat(resString, separatedString);
    free(separatedString);
  }
  return resString;
}

int main()
{
  char *array[] = {"This", "is", "the", "way"};
  string_array strArray = {
      .array = array,
      .size = 4,
  };
  char *res = my_join(&strArray, " ");
  printf("%s\n", res);
  return 0;
}