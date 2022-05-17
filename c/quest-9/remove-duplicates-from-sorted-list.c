#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
  int val;
  struct s_listnode *next;
} listnode;
#endif

listnode *newElem(listnode *head, int val)
{
  if (head == NULL)
  {
    listnode *head = (listnode *)malloc(sizeof(listnode));
    head->val = val;
    head->next = NULL;
    return head;
  }
  listnode *list = head;
  while (list->next != NULL)
  {
    list = list->next;
  }
  listnode *newElem = (listnode *)malloc(sizeof(listnode));
  newElem->val = val;
  list->next = newElem;
  return head;
}

void printList(listnode *head)
{
  while (head != NULL)
  {
    printf("%d,", head->val);
    head = head->next;
  }
  printf("\n");
}

bool findInList(listnode *curr, int value)
{
  while (curr != NULL)
  {
    if (curr->val == value)
    {
      return true;
    }
    curr = curr->next;
  }
  return false;
}

listnode *remove_duplicates_from_sorted_list(listnode *param_1)
{
  listnode *prev = NULL;
  listnode *curr = param_1;
  if (curr == NULL)
  {
    return param_1;
  }
  while (curr->next != NULL)
  {
    printf("find: %d, InList: %d\n", curr->val, findInList(curr->next, curr->val));
    if (findInList(curr->next, curr->val))
    {
      if (prev == NULL)
      {
        param_1 = curr->next;
        curr = curr->next;
        continue;
      }
      else
      {
        prev->next = curr->next;
        curr = prev;
      }
    }
    prev = curr;
    curr = curr->next;
  }
  return param_1;
}

int main()
{
  listnode *List1 = NULL;
  List1 = newElem(List1, 1);
  newElem(List1, 2);
  newElem(List1, 2);
  newElem(List1, 2);
  newElem(List1, 4);
  newElem(List1, 6);
  newElem(List1, 6);
  newElem(List1, 8);
  printList(List1);

  listnode *newList = remove_duplicates_from_sorted_list(List1);
  printList(newList);

  /* printList(newLst); */
  return 0;
}
