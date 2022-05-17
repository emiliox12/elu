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

#ifndef STRUCT_LISTNODE_ARRAY
#define STRUCT_LISTNODE_ARRAY
typedef struct s_listnode_array
{
  int size;
  listnode **array;
} listnode_array;
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

listnode *merge_k_sorted_lists(listnode_array *listArray)
{
  listnode *head = NULL;
  int pos = -1;
  for (size_t i = 0; i < listArray->size; i++)
  {
    if (listArray->array[i] == NULL)
    {
      continue;
    }
    if (head == NULL || head->val > listArray->array[i]->val)
    {
      head = listArray->array[i];
      pos = i;
    }
  }

  listArray->array[pos] = listArray->array[pos]->next;
  bool listsEmpty = false;
  listnode *curr = head;
  while (!listsEmpty)
  {
    listnode *least = NULL;
    int pos = -1;
    for (size_t i = 0; i < listArray->size; i++)
    {
      if (listArray->array[i] == NULL)
      {
        continue;
      }
      else if (least == NULL || least->val > listArray->array[i]->val)
      {
        least = listArray->array[i];
        pos = i;
      }
    }
    if (least == NULL)
    {
      listsEmpty = true;
    }
    else
    {
      listArray->array[pos] = listArray->array[pos]->next;
      curr->next = least;
      curr = least;
    }
  }
  return head;
}

int main()
{
  listnode *List1 = NULL;
  List1 = newElem(List1, 2);
  newElem(List1, 4);
  newElem(List1, 6);
  newElem(List1, 8);
  printList(List1);
  listnode *List2 = NULL;
  List2 = newElem(List2, 1);
  newElem(List2, 3);
  newElem(List2, 5);
  newElem(List2, 7);
  newElem(List2, 9);
  printList(List2);
  listnode *List3 = NULL;
  List3 = newElem(List3, 1);
  newElem(List3, 3);
  newElem(List3, 6);
  newElem(List3, 9);
  newElem(List3, 12);
  printList(List3);
  listnode_array *listArr = malloc(sizeof(listnode_array));
  listnode *array[] = {List1, List2, List3};
  listArr->array = array;
  listArr->size = 3;
  listnode *newList = merge_k_sorted_lists(listArr);
  printList(newList);
  return 0;
}
