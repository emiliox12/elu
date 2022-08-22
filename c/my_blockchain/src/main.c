#include <main.h>
#include <blocks.h>
#include <nodes.h>

void printBlockchain(node *head)
{
  node *curr = head;
  while (curr)
  {
    printNode(curr);
    curr = curr->next;
  }
}

void syncBlockchain(node *head)
{
  node *curr = head;
  block *start = NULL;
  while (curr)
  {
    block *block = curr->block;
    while (block)
    {
      start = add_block_sync(start, block->bid);
      block = block->next;
    }
    curr = curr->next;
  }
  curr = head;
  while (curr)
  {
    copy_blocks(curr, start);
    curr = curr->next;
  }
  free_list(start);
}

void saveBlockChain(node *head)
{
  node *curr = head;
  block *start = NULL;
  while (curr)
  {
    block *block = curr->block;
    while (block)
    {
        }
    curr = curr->next;
  }
  curr = head;
  while (curr)
  {
    curr->block = start;
    curr = curr->next;
  }
}

int main(int argc, char const *argv[])
{
  node_res nodeRes = add_node(NULL, 1);
  if (nodeRes.err)
  {
    launch_error(nodeRes.err);
    return nodeRes.err;
  }
  node *head = nodeRes.res;
  block_res blockRes = add_block(head, 1, "vslkn");
  if (blockRes.err)
  {
    launch_error(blockRes.err);
    return blockRes.err;
  }
  node_res node2Res = add_node(head, 2);
  if (node2Res.err)
  {
    launch_error(node2Res.err);
    return node2Res.err;
  }
  blockRes = add_block(head, 2, "b");
  if (blockRes.err)
  {
    launch_error(blockRes.err);
    return blockRes.err;
  }
  // syncBlockchain(head);
  blockRes = add_block(head, 2, "hshsh");
  if (blockRes.err)
  {
    launch_error(blockRes.err);
    return blockRes.err;
  }
  printBlockchain(head);
  printf("===================remove hshsh\n");
  remove_block(head, "hshsh");
  /* if (nodeRes.err)
  {
    launch_error(nodeRes.err);
    return nodeRes.err;
  }
  head = nodeRes.res; */
  printf("===================PRINT BLOCKCHAIN b\n");
  printBlockchain(head);
  return 0;
}