/*
 * traverse.c
 */
#include "list.h"
#include "traverse.h"

int pre_order(const BiTreeNode *node, List *list) {

    /* Load the list with a preorder listing of the tree. */
    if (!bitree_is_eob(node))
    {
        if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0)
            return -1;

        if (!bitree_is_eob(bitree_left(node)))
            if (pre_order(bitree_left(node), list) != 0)
                return -1;

        if (!bitree_is_eob(bitree_right(node)))
            if (pre_order(bitree_right(node), list) != 0)
                return -1;
    }

    return 0;
}

int in_order(const BiTreeNode *node, List *list) {

    /* Load the list with an inorder listing of the tree. */
    if (!bitree_is_eob(node)) {

        if (!bitree_is_eob(bitree_left(node)))
            if (in_order(bitree_left(node), list) != 0)
                return -1;

        if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0)
            return -1;

        if (!bitree_is_eob(bitree_right(node)))
            if (in_order(bitree_right(node), list) != 0)
                return -1;
    }

    return 0;
}

int post_order(const BiTreeNode *node, List *list) {

    /* Load the list with a postorder listing of the tree. */
    if (!bitree_is_eob(node)) {

        if (!bitree_is_eob(bitree_left(node)))
            if (post_order(bitree_left(node), list) != 0)
                return -1;

        if (!bitree_is_eob(bitree_right(node)))
            if (post_order(bitree_right(node), list) != 0)
                return -1;

        if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0)
            return -1;
    }

    return 0;
}

