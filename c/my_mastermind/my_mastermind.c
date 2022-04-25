#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

bool isDigit(char code)
{
  return code >= 48 && code <= 55;
}

bool checkCode(char *code, char *inputCode)
{
  int wellPlaced = 0;
  int missPlaced = 0;
  for (int i = 0; inputCode[i]; i++)
  {
    if (code[i] == inputCode[i])
    {
      wellPlaced++;
      continue;
    }
    for (int j = 0; inputCode[j]; j++)
    {
      if (inputCode[i] == code[j])
      {
        missPlaced++;
      }
    }
  }
  if (wellPlaced == 4)
  {
    return true;
  }
  printf("Well placed pieces: %d\nMisplaced pieces: %d\n", wellPlaced, missPlaced);
  return false;
}

bool validateCode(char *code)
{
  int i = 0;
  while (code[i])
  {
    if (!isDigit(code[i]))
    {
      printf("Its not a valid number\n");
      return false;
    }
    for (int j = 0; j < i; j++)
    {
      if (code[i] == code[j])
      {
        printf("It repeats\n");
        return false;
      }
    }
    i++;
  }
  if (i != 4)
  {
    printf("wrong Length: %d\n", i);
    return false;
  }
  return true;
}

void start_game(char *code, int attempts)
{
  int i = 0;
  while (i < attempts)
  {
    printf("---\nRound %d\n>", i);
    char inputCode[10];
    scanf("%s", inputCode);
    if (!validateCode(inputCode))
    {
      printf("Wrong input!\n");
      continue;
    }
    bool didWin = checkCode(code, inputCode);
    if (didWin)
    {
      printf("Congratz! You did it!\n");
      return;
      ;
    }
    i++;
  }
  printf("The code was: %s\nSorry, better luck next time\n", code);
}

void createCode(char **passcode)
{
  time_t t;
  srand(time(&t));
  char *code = malloc(sizeof(char) * 4);
  for (int i = 0; i < 4; i++)
  {
    int randomIndex = rand() % 8;
    bool assign = true;
    for (int j = 0; j < i; j++)
    {
      if (randomIndex + '0' == code[j])
      {
        i--;
        assign = false;
        break;
      }
    }
    if (assign)
    {
      code[i] = randomIndex + '0';
    }
  }
  strcpy(*passcode, code);
  free(code);
}

int main(int _, char **av)
{
  char *code = malloc(sizeof(char) * 4);
  int attemps = 10;
  int i = 1;
  while (av[i])
  {
    if (strcmp(av[i], "-c") == 0)
    {
      if (!validateCode(av[i + 1]))
      {
        printf("Invalid Code\n");
        return 0;
      }
      printf("Code received\n");
      strcpy(code, av[i + 1]);
    }
    else if (strcmp(av[i], "-t") == 0)
    {
      printf("Attempts received\n");
      attemps = atoi(av[i + 1]);
    }
    i++;
  }
  printf("Will you find the secret code?\n");
  if (strlen(code) == 0)
  {
    createCode(&code);
    // printf("Code created: %s\n", code);
  }
  printf("Attempts: %d\n", attemps);
  start_game(code, attemps);
  free(code);
  return 0;
}