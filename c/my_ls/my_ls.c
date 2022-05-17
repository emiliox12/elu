#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <time.h>

#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
  __time_t time;
  char *name;
  struct s_listnode *next;
} listnode;
#endif

void printList(listnode *curr)
{
  while (curr != NULL)
  {
    char buff[20];
    time_t now = time(NULL);
    strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&curr->time));
    printf("%s: %s\n", curr->name, buff);
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
  while (curr->next != NULL)
  {
    if (curr->time < elem->time)
    {
      prev->next = elem;
      elem->next = curr;
      return head;
    }
    curr = curr->next;
  }
  curr->next = elem;
  return head;
}

int main(int argc, char const *argv[])
{
  struct dirent *dp;
  struct dirent *result;
  struct stat attr;
  bool isSorted = true;
  bool showHidden = true;
  DIR *directory = opendir(argv[1]);
  listnode *head = (listnode *)malloc(sizeof(listnode));
  head = NULL;
  while ((dp = readdir(directory)) != NULL)
  {
    if (showHidden || !(dp->d_name[0] == '.'))
    {
      stat(dp->d_name, &attr);
      listnode *elem = (listnode *)malloc(sizeof(listnode));
      elem->time = attr.st_mtim.tv_sec;
      elem->name = dp->d_name;
      elem->next = NULL;
      /* printf("%s, %ld\n", elem->name, elem->time); */
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
  printList(head);
  return 0;
}
