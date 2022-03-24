#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void start_game(char *code, int attempts)
{
}

void createCode(char **code)
{
  int array[10];
  for (int i = 0; i < 10; i++)
  { // fill array
    array[i] = i;
    printf("%d,", array[i]);
  }
  for (int i = 0; i < 10; i++)
  { // shuffle array
    int temp = array[i];
    int randomIndex = rand() % 10;
    array[i] = array[randomIndex];
    array[randomIndex] = temp;
  }
  for (int i = 0; i < 4; i++)
  {
    *code[i] = array[i];
  }
  printf("code: %s\n", *code);
}

int main(int ac, char **av)
{
  char *code;
  int attemps = 10;
  int i = 1;
  while (av[i])
  {
    printf("av[%d]: /%s/\n", i, av[i]);
    printf("check: %d\n", av[i] == "-c");
    if (av[i] == "-c")
    {
      printf("Will you find the secret code?\n---\n");
      code = av[i + 1];
    }
    else if (av[i] == "-t")
    {
      attemps = atoi(av[i + 1]);
    }
    i++;
  }
  printf("Will you find the secret code?\n---\n");
  printf("code: %s\n", code);
  printf("code: %d\n", !code);
  if (!code)
  {
    printf("!code\n");
    createCode(&code);
  }
  /* start_game(code, attemps); */
  return 0;
}