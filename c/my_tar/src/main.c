#include <main.h>
#include <list.h>

bool createAndAppendHeader(char *name, int fd, struct archive_header **new)
{
  struct stat s;
  stat(name, &s);
  char *fileSize = malloc(sizeof(char) * MAX_SIZE_LENGTH);
  if (*new == NULL)
  {
    return false;
  }
  (*new)->name = malloc(sizeof(char) * MAX_NAME_LENGTH + 1);
  memset((*new)->name, '\0', MAX_NAME_LENGTH + 1);
  strcpy((*new)->name, name);
  (*new)->size = s.st_size;
  write(fd, (*new)->name, MAX_NAME_LENGTH);
  memset(fileSize, '\0', MAX_SIZE_LENGTH);
  int nb = sprintf(fileSize, "%d", (*new)->size);
  fileSize[nb] = '\0';
  write(fd, fileSize, MAX_SIZE_LENGTH);
  return true;
}

bool appendItemToArchive(int fd, char *name, enum fileType type)
{
  int fdFile;
  char readBuffer[BLOCK_SIZE + 1];
  int nb;
  struct archive_header *new = malloc(sizeof(struct archive_header));

  if ((fdFile = open(name, O_RDONLY)) == -1)
  {
    return false;
  }
  if (!createAndAppendHeader(name, fd, &new))
  {
    return false;
  }
  while ((nb = read(fdFile, readBuffer, BLOCK_SIZE)) > 0)
  {
    if (nb == 0)
    {
      return true;
    }
    readBuffer[nb] = '\0';
    nb = write(fd, readBuffer, BLOCK_SIZE);
    memset(readBuffer, '\0', BLOCK_SIZE);
  }
  return true;
}

bool createArchive(data_t *data)
{
  int fd = open(data->archiveName, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
  if (fd == -1)
  {
    printf("something went wrong while creating the archive");
    return false;
  }
  struct s_largs *tmp = data->args;
  while (tmp)
  {
    if (!appendItemToArchive(fd, tmp->argName, tmp->type))
    {
      return false;
    }
    tmp = tmp->next;
  }
}

int main(int argc, char const *argv[])
{

  return 0;
}