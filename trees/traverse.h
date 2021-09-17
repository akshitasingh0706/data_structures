/*
 * traverse.h
 */
#ifndef TRAVERSE_H
#define TRAVERSE_H

#include "bitree.h"
#include "list.h"

/* Public Interface */
int pre_order(const BiTreeNode *node, List *list);

int in_order(const BiTreeNode *node, List *list);

int post_order(const BiTreeNode *node, List *list);

#endif
