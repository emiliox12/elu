#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void output_file(char *fileName)
{
  FILE *ptr;
  char ch;
  if ((ptr = fopen(fileName, "r")) == NULL)
  {
    printf("Error! opening file");
    exit(1);
  }
  int i = 0;
  ch = fgetc(ptr);
  do
  {
    printf("%c", ch);
    ch = fgetc(ptr);
  } while (ch != EOF);
  fclose(ptr);
}

int main(int ac, char **av)
{
  int i = 1;
  char cwd[255];
  getcwd(cwd, sizeof(cwd));
  while (av[i])
  {
    char *result = malloc(strlen(cwd) + strlen(av[i]) + 10);
    strcpy(result, cwd);
    strcat(result, "/");
    strcat(result, av[i]);
    output_file(result);
    i++;
  }
  return 0;
}