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

int getListSize(listnode *head)
{
  int count = 0;
  while (head != NULL)
  {
    head = head->next;
    count++;
  }
  return count;
}

listnode *remove_nth_node_from_end_of_list(listnode *param_1, int param_2)
{
  int size = getListSize(param_1);
  int removeIndex = size - param_2;
  printf("removeIndex: %d\n", removeIndex);
  int currentIndex = 0;
  listnode *curr = param_1;
  listnode *prev = NULL;
  while (curr != NULL)
  {
    printf("currentIndex: %d, curr: %d, prev: %d\n", currentIndex, curr->val, (prev != NULL) ? prev->val : -1);
    if (currentIndex == removeIndex)
    {
      if (prev == NULL)
      {
        param_1 = curr->next;
        curr = curr->next;
        currentIndex++;
        continue;
      }
      else
      {
        prev->next = curr->next;
      }
    }
    prev = curr;
    curr = curr->next;
    currentIndex++;
  }
  return param_1;
}

int main()
{
  listnode *List1 = NULL;
  List1 = newElem(List1, 1);
  newElem(List1, 2);
  /* newElem(List1, 4);
  newElem(List1, 6);
  newElem(List1, 8); */
  printList(List1);

  listnode *newList = remove_nth_node_from_end_of_list(List1, 2);
  printList(newList);

  /* printList(newLst); */
  return 0;
}
