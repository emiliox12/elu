#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *OrderTheLength(char **input)
{
  int arrSize = 0;
  while (input[arrSize])
  {
    arrSize++;
  }
  arrSize++;
  printf("arrSize: %d\n", arrSize);
  int *intArr = malloc(sizeof(int) * arrSize);
  for (int i = 0; i <= arrSize; i++)
  {
    int inputLen = strlen(input[i]);
    intArr[i] = inputLen;
  }
  for (int i = 0; i < arrSize + 1; i++)
  {
    for (int j = i; j < arrSize + 1; j++)
    {
      printf("j: %d, k:%d\n", intArr[j], intArr[j + 1]);
      if (intArr[j] > intArr[j + 1])
      {
        int elem = intArr[j];
        intArr[j] = intArr[j + 1];
        intArr[j + 1] = elem;
      }
      else
      {
        break;
      }
    }
  }
  return intArr;
}

int main()
{
  char **input = malloc(sizeof(char *) * (3 + 1));
  for (int i = 0; i < 6; i++)
    input[i] = (char *)malloc(sizeof(char) * 50);
  input[0] = "test1";
  input[1] = "testfwefewfest";
  input[2] = "test test test and test";
  input[3] = NULL;
  int *ret = OrderTheLength(input);
  for (int i = 0; i < 3; i++)
    printf("%d ", ret[i]);
}
