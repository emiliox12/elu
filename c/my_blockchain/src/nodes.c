#include <nodes.h>
#include <blocks.h>

node *find_node(node *head, int nid)
{
  node *curr = head;
  if (!curr)
  {
    return NULL;
  }
  while (curr)
  {
    if (curr->nid == nid)
      return curr;
    curr = curr->next;
  }
  return NULL;
}

void *free_node(node *node)
{
  if (node->block)
    free_list(node->block);
  free(node);
}

node_res remove_node(node *head, int nid)
{
  if (!find_node(head, nid))
  {
    node_res res = {
        NODE_DOESN_T_EXIST,
        NULL,
    };
    return res;
  }
  if (head->nid == nid)
  {
    node *newHead = head->next;
    free_node(head);
    return (node_res){
        OK,
        newHead,
    };
  }
  node *curr = head->next;
  node *last = head;
  while (curr)
  {
    if (curr->nid == nid)
    {
      last->next = curr->next;
      free_node(curr);
      return (node_res){
          OK,
          head,
      };
    }
    last = curr;
    curr = curr->next;
  }
  return (node_res){
      NODE_DOESN_T_EXIST,
      NULL,
  };
}

node_res add_node(node *head, int nid)
{
  if (!head)
  {
    node *elem = (node *)malloc(sizeof(node));
    elem->nid = nid;
    elem->block = NULL;
    elem->next = NULL;
    return (node_res){
        OK,
        elem,
    };
  }
  if (find_node(head, nid))
  {
    return (node_res){
        THIS_NODE_ALREADY_EXISTS,
        NULL,
    };
  }
  node *curr = head;
  while (curr->next)
  {
    curr = curr->next;
  }
  node *elem = (node *)malloc(sizeof(node));
  elem->nid = nid;
  elem->block = NULL;
  elem->next = NULL;
  curr->next = elem;
  return (node_res){
      OK,
      elem,
  };
}

void printNode(node *node)
{
  printf("[%d]: ", node->nid);
  block *block = node->block;
  while (block)
  {
    printf("%s->", block->bid);
    block = block->next;
  }
  printf("\n");
}
