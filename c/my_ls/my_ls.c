#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <time.h>

#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
  long time;
  char *name;
  int type;
  struct s_listnode *next;
} listnode;
#endif

int getTypeColor(int type)
{
  switch (type)
  {
  case 4:
    return 35;
  case 8:
    return 36;
  case 9:
    return 32;
  default:
    return 37;
  }
}

void printList(listnode *curr)
{
  while (curr != NULL)
  {
    printf("\033[0;%dm%s\033[0m\n", getTypeColor(curr->type), curr->name);
    curr = curr->next;
  }
  printf("\n");
}

listnode *addElementLast(listnode *head, listnode *elem)
{
  if (head == NULL)
  {
    return elem;
  }
  listnode *list = head;
  while (list->next != NULL)
  {
    list = list->next;
  }
  list->next = elem;
  return head;
}

listnode *addElementSorted(listnode *head, listnode *elem)
{
  if (head == NULL)
  {
    return elem;
  }
  if (head->time < elem->time)
  {
    elem->next = head;
    return elem;
  }
  if (head->next == NULL)
  {
    head->next = elem;
    return head;
  }
  listnode *curr = head->next;
  listnode *prev = head;
  while (curr != NULL)
  {
    if (curr->time < elem->time)
    {
      prev->next = elem;
      elem->next = curr;
      return head;
    }
    else if (curr->time == elem->time)
    {
      char *elemName = (elem->name[0] == '.') ? elem->name + 1 : elem->name;
      char *currName = (curr->name[0] == '.') ? curr->name + 1 : curr->name;
      int compare = strcmp(elemName, currName);
      if (compare < 0)
      {
        prev->next = elem;
        elem->next = curr;
        return head;
      }
    }
    prev = curr;
    curr = curr->next;
  }
  prev->next = elem;
  return head;
}

int main(int argc, char const *argv[])
{
  struct dirent *dp;
  struct stat attr;
  bool isSorted = false;
  bool showHidden = false;
  int i = 1;
  while (argv[i] && argv[i][0] == '-')
  {
    if (strcmp(argv[i], "-at") == 0 || strcmp(argv[i], "-ta") == 0)
    {
      isSorted = true;
      showHidden = true;
    }
    else if (strcmp(argv[i], "-t") == 0)
    {
      isSorted = true;
    }
    else if (strcmp(argv[i], "-a") == 0)
    {
      showHidden = true;
    }
    i++;
  }
  if (!argv[i])
  {
    argv[i] = ".";
    argc++;
  }
  while (i < argc)
  {
    DIR *directory = opendir(argv[i]);
    if (directory == NULL)
    {
      printf("Directory might not exist or can not be accessed\n");
      return 0;
    }
    listnode *head = (listnode *)malloc(sizeof(listnode));
    head = NULL;
    while ((dp = readdir(directory)) != NULL)
    {
      if (showHidden || !(dp->d_name[0] == '.'))
      {
        char dirPath[50];
        strcpy(dirPath, argv[argc - 1]);
        lstat(strcat(dirPath, dp->d_name), &attr);
        listnode *elem = (listnode *)malloc(sizeof(listnode));
        elem->time = attr.st_mtim.tv_sec;
        elem->name = dp->d_name;
        elem->type = (dp->d_name[0] == '.') ? 9 : dp->d_type;
        elem->next = NULL;
        if (isSorted)
        {
          head = addElementSorted(head, elem);
        }
        else
        {
          head = addElementLast(head, elem);
        }
      }
    }
    closedir(directory);
    printList(head);
    printf("\n\n");
    i++;
  }
  return 0;
}
