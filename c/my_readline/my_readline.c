#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>

int READLINE_READ_SIZE;
char *STORAGE;

void str_cut(char *str, char cut)
{
  for (size_t i = 0; str[i]; i++)
  {
    if (str[i] == cut)
    {
      str[i] = '\0';
      return;
    }
  }
}

char *my_readline(int fd)
{
  char buffer[READLINE_READ_SIZE + 1];
  char *line = "";
  memset(buffer, '\0', READLINE_READ_SIZE);
  int readBytes;
  if (STORAGE)
  {
    char *tmp = NULL;
    if ((tmp = strchr(STORAGE, '\n')) != NULL)
    {
      line = malloc(sizeof(char) * strlen(STORAGE) - strlen(tmp));
      strncpy(line, STORAGE, strlen(STORAGE) - strlen(tmp));
      STORAGE = strdup(tmp + 1);
      return line;
    }
    else
    {
      line = strdup(STORAGE);
      free(STORAGE);
      STORAGE = NULL;
    }
  }
  while ((readBytes = read(fd, buffer, READLINE_READ_SIZE)) > 0)
  {
    buffer[readBytes] = '\0';
    char *extra = strchr(buffer, '\n');
    if (extra != NULL)
    {
      STORAGE = strdup(extra + 1);
      char *tmp = malloc((sizeof(char) * READLINE_READ_SIZE + 1) + sizeof(char) * strlen(line + 1));
      memset(tmp, '\0', READLINE_READ_SIZE + strlen(line + 1));
      if (line)
        strcpy(tmp, line);
      str_cut(buffer, '\n');
      strcat(tmp, buffer);
      if (line)
        free(line);
      line = NULL;
      line = tmp;
      break;
    }
    else
    {
      char *tmp = malloc((sizeof(char) * READLINE_READ_SIZE + 1) + sizeof(char) * strlen(line + 1));
      memset(tmp, '\0', READLINE_READ_SIZE + strlen(line + 1));
      strcat(tmp, line);
      strcat(tmp, buffer);
      if (line)
        free(line);
      line = NULL;
      line = tmp;
    }
  }
  if (!strlen(line))
  {
    return NULL;
  }
  return line;
}

READLINE_READ_SIZE = 512;

int main(int ac, char **av)
{
  char *str = NULL;

  int fd = open("./file.txt", O_RDONLY);
  while ((str = my_readline(fd)) != NULL)
  {
    printf("%s\n", str);
    free(str);
  }
  close(fd);
  return 0;
}
