#ifndef BLOCKS_DOT_H
#define BLOCKS_DOT_H

#include <main.h>

bool check_bid(block *head, char *bid);
void *free_list(block *block);
block *copy_blocks(node *node, block *start);
block *add_block_sync(block *head, char *bid);
block_res add_block(node *head, int nid, char *bid);
block_res remove_block(node *head, char *bid);
void printBlocks(block *head);

#endif