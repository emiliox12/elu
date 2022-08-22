#ifndef MAIN_DOT_H
#define MAIN_DOT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errors.h>

typedef struct s_block
{
  char *bid;
  struct s_block *next;
} block;

typedef struct s_node
{
  int nid;
  struct s_block *block;
  struct s_node *next;
} node;

typedef struct block_res
{
  errors err;
  struct s_block *res;
} block_res;

typedef struct node_res
{
  errors err;
  struct s_node *res;
} node_res;

#endif