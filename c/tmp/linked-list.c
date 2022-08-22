#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
  int value;
  struct s_list *next;
} t_list;

t_list *newElem(t_list *head, int value)
{
  if (head == NULL)
  {
    t_list *head = (t_list *)malloc(sizeof(t_list));
    head->value = value;
    head->next = NULL;
    return head;
  }
  t_list *list = head;
  while (list->next != NULL)
  {
    list = list->next;
  }
  t_list *newElem = (t_list *)malloc(sizeof(t_list));
  newElem->value = value;
  list->next = newElem;
  return head;
}

void printList(t_list *head)
{
  while (head != NULL)
  {
    printf("%d,", head->value);
    head = head->next;
  }
  printf("\n");
}

t_list *addElementSorted(t_list *head, int value)
{
  t_list *elem = (t_list *)malloc(sizeof(t_list));
  elem->value = value;
  if (head == NULL)
  {
    printList(elem);
    return elem;
  }
  if (head->value < elem->value)
  {
    elem->next = head;
    printList(elem);
    return elem;
  }
  if (head->next == NULL)
  {
    head->next = elem;
    printList(head);
    return head;
  }
  t_list *curr = head->next;
  t_list *prev = head;
  while (curr != NULL)
  {
    if (curr->value < elem->value)
    {
      prev->next = elem;
      elem->next = curr;
      printList(head);
      return head;
    }
    prev = curr;
    curr = curr->next;
  }
  prev->next = elem;
  printList(head);
  return head;
}

t_list *mergeList(t_list *list_a, t_list *list_b)
{
  t_list *head = NULL;
  if (list_a->value > list_b->value)
  {
    head = list_b;
    list_b = list_b->next;
  }
  else
  {
    head = list_a;
    list_a = list_a->next;
  }
  t_list *curr = head;
  while (list_a != NULL || list_b != NULL)
  {
    if (list_a == NULL || list_a->value > list_b->value)
    {
      curr->next = list_b;
      list_b = list_b->next;
    }
    else
    {
      curr->next = list_a;
      list_a = list_a->next;
    }
    curr = curr->next;
  }
  return head;
}

int main()
{
  t_list *List1 = NULL;
  List1 = addElementSorted(List1, 11);
  List1 = addElementSorted(List1, 10);
  List1 = addElementSorted(List1, 8);
  List1 = addElementSorted(List1, 6);
  List1 = addElementSorted(List1, 1);
  List1 = addElementSorted(List1, 2);
  printf("\033[0;35m");
  printList(List1);
  printf("\033[0m");
  return 0;
}
