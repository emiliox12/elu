#ifndef NODES_DOT_H
#define NODES_DOT_H

#include <main.h>

node *find_node(node *head, int nid);
void *free_node(node *node);
node_res remove_node(node *head, int nid);
node_res add_node(node *head, int nid);
void printNode(node *node);

#endif