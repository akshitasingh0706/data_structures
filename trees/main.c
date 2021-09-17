#include <stdio.h>
#include "list.h"
#include "bitree.h"
#include "traverse.h"

/* ****************** DEFINE ad hoc functions ************************* */

#define bitree_ins_root(tree, data) bitree_ins_left(tree, NULL, data)
#define max(a,b) ((a) > (b) ? (a) : (b))

/* ****************** DEFINE print, destroy **************************** */

void destroy(void*data)
{
    (void) data;
}

void print(const void *data)
{
    printf("[%d]", *(int*)data);
}

/* ****************** BUILD tree1 and tree 2 as per HW *********************** */

void fillTree1(BiTree* tree, int* node)
{
    bitree_ins_root(tree,                                          node++); // 1
    bitree_ins_left(tree,  bitree_root(tree),                      node++); // 2
    bitree_ins_right(tree, bitree_root(tree),                      node++); // 3
    bitree_ins_left(tree,  bitree_root(tree)->left,                node++); // 4
    bitree_ins_left(tree,  bitree_root(tree)->right,               node++); // 5
    bitree_ins_right(tree, bitree_root(tree)->right,               node++); // 6
    bitree_ins_left(tree,  bitree_root(tree)->left->left,          node++); // 7
    bitree_ins_right(tree, bitree_root(tree)->right->right,        node++); // 8
    bitree_ins_right(tree, bitree_root(tree)->right->right->right, node)  ; // 9
}

void fillTree2(BiTree* tree, int* node)
{
    bitree_ins_root(tree,                                 node++); // 6
    bitree_ins_left(tree,  bitree_root(tree),             node++); // 4
    bitree_ins_left(tree,  bitree_root(tree)->left,       node++); // 2
    bitree_ins_right(tree, bitree_root(tree)->left,       node++); // 5
    bitree_ins_left(tree,  bitree_root(tree)->left->left, node++); // 1
    bitree_ins_right(tree, bitree_root(tree)->left->left, node++); // 3
    bitree_ins_right(tree, bitree_root(tree),             node++); // 8
    bitree_ins_left(tree,  bitree_root(tree)->right,      node++); // 7
    bitree_ins_right(tree, bitree_root(tree)->right,      node);   // 9
}

/* ****************** COUNT NUMBER OF LEAVES **************************** */

void count_leaves_rec(const BiTreeNode* node, int* count)
{
    if (bitree_is_leaf(node))
        ++(*count);
    else
    {
        if (bitree_left(node))
            count_leaves_rec(bitree_left(node), count);
        if (bitree_right(node))
            count_leaves_rec(bitree_right(node), count);
    }
}

int count_leaves(BiTree *tree)
{
    int count = 0;
    count_leaves_rec(bitree_root(tree), &count);
    return count;
}

/* ****************** COUNT NUMBER OF NON LEAVES ********************** */

void count_non_leaves_rec(const BiTreeNode* node, int* count)
{
    if (bitree_is_leaf(node))
        return;
    else
    {
        ++(*count);
        if (bitree_left(node))
            count_non_leaves_rec(bitree_left(node), count);
        if (bitree_right(node))
            count_non_leaves_rec(bitree_right(node), count);
    }
}

int count_non_leaves(BiTree *tree)
{
    int count = 0;
    count_non_leaves_rec(bitree_root(tree), &count);
    return count;
}

/* ************************* CALCULATE HEIGHT ************************ */

int get_height_rec(const BiTreeNode* node, int level)
{
    if (bitree_is_leaf(node))
        return level;
    else
    {
        ++level;
        int  left = bitree_left(node)  ? get_height_rec(bitree_left(node), level) : level;
        int right = bitree_right(node) ? get_height_rec(bitree_right(node), level) : level;
        return max(left, right);
    }
}

int get_height(const BiTree* tree)
{
    return bitree_root(tree) ? get_height_rec(bitree_root(tree), 1) : 0;
}

/* ************************* PRINT PRE ORDER TRAVERSAL ******************************* */

void print_pre_order(BiTree *tree, void (*print)(const void *data))
{
       List list;
       list_init(&list, NULL);
       pre_order(bitree_root(tree), &list);
    
       ListElmt *node = list_head(&list);
       while (node)
       {
           print(list_data(node));
           node = list_next(node);
       }
       printf("\n");
}

/* ************************* PRINT IN ORDER TRAVERSAL ******************************* */

void print_in_order(BiTree *tree, void (*print)(const void *data))
{
       List list;
       list_init(&list, NULL);
       in_order(bitree_root(tree), &list);
    
       ListElmt *node = list_head(&list);
       while (node)
       {
           print(list_data(node));
           node = list_next(node);
       }
       printf("\n");
}

/* ************************* PRINT POST ORDER TRAVERSAL ******************************* */

void print_post_order(BiTree *tree, void (*print)(const void *data))
{
       List list;
       list_init(&list, NULL);
       post_order(bitree_root(tree), &list);
    
       ListElmt *node = list_head(&list);
       while (node)
       {
           print(list_data(node));
           node = list_next(node);
       }
       printf("\n");
}

/* ************************* REMOVE LEAVES FROM TREE ******************************* */

void remove_leaves_rec(BiTree* tree, BiTreeNode* node)
{
    if (bitree_left(node))
    {
        if (bitree_is_leaf(bitree_left(node)))
            bitree_rem_left(tree, node);
        else
            remove_leaves_rec(tree, bitree_left(node));
    }
    if (bitree_right(node))
    {
        if (bitree_is_leaf(bitree_right(node)))
            bitree_rem_right(tree, node);
        else
            remove_leaves_rec(tree, bitree_right(node));
    }
}

void remove_leaves(BiTree* tree)
{
    if (bitree_root(tree))
    {
        if (bitree_is_leaf(bitree_root(tree)))
            bitree_rem_left(tree, NULL);
        else
            remove_leaves_rec(tree, bitree_root(tree));
    }
}

/* ************************* MAIN FUNCTION ******************************* */

int main(int argc, char const *argv[])
{
    BiTree* tree = malloc(sizeof(*tree));
    bitree_init(tree, destroy);
    
    printf(">>>>>>>>>>>>> TREE 1 >>>>>>>>>>>>>>\n");

    List tree1_list;
    list_init(&tree1_list, NULL);
    int tree1_array[] = {1,2,3,4,5,6,7,8,9};
    fillTree1(tree, tree1_array);
    
    printf("Number of Leaves: %d\n", count_leaves(tree));
    printf("Number of Non-Leaves: %d\n", count_non_leaves(tree));
    printf("Tree Height: %d\n", get_height(tree));
    
    printf("Pre-Order: \n");
    print_pre_order(tree, print);
    
    printf("In-Order: \n");
    print_in_order(tree, print);
    
    printf("Post-Order: \n");
    print_post_order(tree, print);
    
    printf("**** Remove Leaves ******\n");
    remove_leaves(tree);
    
    printf("New Number of Leaves: %d\n", count_leaves(tree));
    printf("New Number of Non-Leaves: %d\n", count_non_leaves(tree));
    printf("New Tree Height: %d\n", get_height(tree));
    
    printf("New Pre-Order: \n");
    print_pre_order(tree, print);
    
    printf("New In-Order (After Leave Removal): \n");
    print_in_order(tree, print);
    
    printf("New Post-Order (After Leave Removal): \n");
    print_post_order(tree, print);
    
    printf(">>>>>>>>>>>>> TREE 2 >>>>>>>>>>>>>>\n");

    List tree2_list;
    list_init(&tree2_list, NULL);
    int tree2_array[] = {6,4,2,5,1,3,8,7,9};
    fillTree2(tree, tree2_array);
    
    printf("Number of Leaves: %d\n", count_leaves(tree));
    printf("Number of Non-Leaves: %d\n", count_non_leaves(tree));
    printf("Tree Height: %d\n", get_height(tree));
    
     printf("Pre-Order: \n");
    print_pre_order(tree, print);
    
    printf("In-Order: \n");
    print_in_order(tree, print);
    
    printf("Post-Order: \n");
    print_post_order(tree, print);
    
    printf("**** Remove Leaves ******\n");
    remove_leaves(tree);
    
    printf("New Number of Leaves: %d\n", count_leaves(tree));
    printf("New Number of Non-Leaves: %d\n", count_non_leaves(tree));
    printf("New Tree Height: %d\n", get_height(tree));
    
    printf("New Pre-Order: \n");
    print_pre_order(tree, print);
    
    printf("New In-Order (After Leave Removal): \n");
    print_in_order(tree, print);
    
    printf("New Post-Order (After Leave Removal): \n");
    print_post_order(tree, print);
}
    
