#include <blocks.h>
#include <nodes.h>

bool check_bid(block *head, char *bid)
{
  block *curr = head;
  if (!curr)
  {
    return false;
  }
  while (curr)
  {
    if (strcmp(curr->bid, bid) == 0)
      return true;
    curr = curr->next;
  }
  return false;
}

void *free_list(block *block)
{
  if (block->next)
  {
    free_list(block->next);
  }
  else
  {
    free(block);
  }
}

block *copy_blocks(node *node, block *start)
{
  free_list(node->block);
  block *head = (block *)malloc(sizeof(block));
  head->bid = start->bid;
  head->next = NULL;
  block *last = head;
  block *curr = start->next;
  while (curr)
  {
    block *elem = (block *)malloc(sizeof(block));
    elem->bid = curr->bid;
    elem->next = NULL;
    last->next = elem;
    last = curr;
    curr = curr->next;
  }
}

block *add_block_sync(block *head, char *bid)
{
  block *curr = head;
  if (!curr)
  {
    block *elem = (block *)malloc(sizeof(block));
    elem->bid = bid;
    elem->next = NULL;
    return elem;
  }
  while (curr->next)
  {
    if (strcmp(curr->bid, bid) == 0)
    {
      return head;
    }
    curr = curr->next;
  }
  if (strcmp(curr->bid, bid) == 0)
  {
    return head;
  }
  block *elem = (block *)malloc(sizeof(block));
  elem->bid = bid;
  elem->next = NULL;
  curr->next = elem;
  return head;
}

block_res add_block(node *head, int nid, char *bid)
{
  node *curr_node = find_node(head, nid);
  if (!curr_node)
  {
    return (block_res){
        NODE_DOESN_T_EXIST,
        NULL,
    };
  }
  if (check_bid(curr_node->block, bid))
  {
    return (block_res){
        THIS_NODE_ALREADY_EXISTS,
        NULL,
    };
  }
  if (!curr_node->block)
  {
    block *elem = (block *)malloc(sizeof(block));
    elem->bid = bid;
    elem->next = NULL;
    curr_node->block = elem;
    return (block_res){
        OK,
        elem,
    };
  }
  block *curr = curr_node->block;
  while (curr->next)
  {
    curr = curr->next;
  }
  block *elem = (block *)malloc(sizeof(block));
  elem->bid = bid;
  elem->next = NULL;
  curr->next = elem;
  return (block_res){
      OK,
      elem,
  };
}

block_res remove_block(node *head, char *bid)
{
  node *curr = head;
  while (curr)
  {
    printf("[%d]: ", curr->nid);
    block *curr_block = curr->block;
    printf("%s->", curr_block->bid);
    if (strcmp(curr_block->bid, bid) == 0)
    {
      curr->block = curr_block->next;
      free(curr_block);
      printf("\n");
      curr = curr->next;
      continue;
    }
    block *prev_block = curr_block;
    curr_block = curr_block->next;
    while (curr_block)
    {
      printf("%s->", curr_block->bid);
      if (strcmp(curr_block->bid, bid) == 0)
      {
        prev_block->next = curr_block->next;
        free(curr_block);
        break;
      }
      prev_block = curr_block;
      curr_block = curr_block->next;
    }
    printf("\n");
    curr = curr->next;
  }
  return (block_res){
      OK,
      NULL,
  };
}

void printBlocks(block *head)
{
  block *block = head;
  while (block)
  {
    printf("%s->", block->bid);
    block = block->next;
  }
  printf("\n");
}
