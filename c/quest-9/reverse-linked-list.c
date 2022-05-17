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

listnode *reverse_linked_list(listnode *curr)
{
  listnode *prev = NULL;
  while (curr != NULL)
  {
    listnode *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

int main()
{
  listnode *List1 = NULL;
  List1 = newElem(List1, 1);
  newElem(List1, 2);
  newElem(List1, 4);
  newElem(List1, 6);
  newElem(List1, 8);
  printList(List1);

  listnode *newLst = reverse_linked_list(List1);
  printList(newLst);
  return 0;
}
