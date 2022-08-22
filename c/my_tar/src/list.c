#include <list.h>
#include <main.h>

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