/*******************************************************************************************
* File Name          : stacktree.c
* Description        : Prog8130 - Assignment 3: Use Stack to traverse a binary tree
*
* Author:            : Gaurav Kalia
* Date:              : 27th March, 2022 
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to store a tree node
typedef struct treenode {
    int number;
    struct treenode *left;
    struct treenode *right;
} TreeNode;

// stack structure
typedef struct stacknode {
    struct treenode *ptrTreeNode;
    struct stacknode *nextStackNode;
} Node;

// tree head
TreeNode *head = NULL;

// stack top
Node *top = NULL;

// tree functions
void addToBinaryTree(const int number);
void printBinaryTreeInOrder(TreeNode* head);

// stack functions
void push(TreeNode *);
TreeNode* pop();

int main(int argc, char* argv[]) {
        int number;                     // to store new number
        int i;                          // used in for loop as index

        // put all the numbers into the binary tree
        // numbers will be provided from command line
        for (i = 1; i < argc; i++) {
            number = atoi(argv[i]);
            addToBinaryTree(number);
        }

        // print the entire tree using In-Order
        // ptrTreeNode time you need to do it using stack
        printBinaryTreeInOrder(head);

        return 0;
}

// this is an implementation you can use to check your assignment 2 code
void addToBinaryTree(const int number) {
        TreeNode* p = head;
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        if (node == NULL) {
            return; // don't handle the error for now
        }
        node->number = number;
        node->left = NULL;
        node->right = NULL;

        if (head == NULL) {
            head = node;
            return;
        }

        while (1) {
            if (p->number < number) {
                if (p->right == NULL) {
                    p->right = node;
                    break;
                }
                else {
                    p = p->right;
                }
            }
            else {
                if (p->left == NULL) {
                    p->left = node;
                    break;
                }
                else {
                    p = p->left;
                }
            }
        }
        return;
}

//====================== You should not modify anything above ==============================//
//==================== You should only modify following functions ==========================//
//============================= do not remove above comments  ==============================//

// FUNCTION      : push
//
// DESCRIPTION   :
//   a function will push a new stack node into a stack
//
// PARAMETERS    :
//   TreeNode* - the new tree node to store
//
// RETURNS       :
//   Nothing
void push(TreeNode *p) {
    // malloc a new stack node using the tree node
    // and push it into the stack

    // you code
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->ptrTreeNode = p;
    newNode->nextStackNode = NULL;

    if (top != NULL)
    {
        /* code */
        Node *head = top;
        while (head->nextStackNode != NULL)
        {
            /* code */
            head = head->nextStackNode;
        }
        head->nextStackNode = newNode;
    }
    else{
        top = newNode;
        return;
    }
    
}

// FUNCTION      : pop
//
// DESCRIPTION   :
//   a function will pop a tree node from the stack
//
// PARAMETERS    :
//   None
//
// RETURNS       :
//   the TreeNode* popped or NULL if the stack is empty
TreeNode* pop() {
    // you code
    Node *ptr = top;
    if (top == NULL)
    {
        /* code */
        return NULL;
    }
    else if (ptr->nextStackNode == NULL)
    {
        /* code */
        Node *tempNode = ptr;
        top = NULL;
        return tempNode->ptrTreeNode;
    }
    while (ptr->nextStackNode->nextStackNode != NULL)
    {
        /* code */
        ptr = ptr->nextStackNode;
    }
    Node *tempNode = ptr->nextStackNode;
    ptr->nextStackNode = NULL;
    return tempNode->ptrTreeNode;
    
}

// FUNCTION      : printBinaryTreeInOrder
//
// DESCRIPTION   :
//   a function will print the entire binary tree out using In-Order
//   using your stack. This is a good place to understand why recursion
//   can usually be changed to iteratives by using stacks
//
// PARAMETERS    :
//   None
//
// RETURNS       :
//   Nothing
void printBinaryTreeInOrder(TreeNode* head) {
    // add code to print data using In-Order starting at the "head" pointer
    // you need to use your stack to print it
    // any recursion call is not allowed
    // one number per line
    // printf("%d\n");

    // you code

    TreeNode *currentTreeNode = head;
    while (currentTreeNode != NULL || top != NULL)
    {
        /* code */
        if (currentTreeNode != NULL)
        {
            /* code */
            // do something using stack
            push(currentTreeNode);
            // move currentTreeNode to its left child
            currentTreeNode = currentTreeNode->left;
        }
        else{
            // do something using stack
            currentTreeNode = pop();
            if(currentTreeNode == NULL);
            printf("%d\n", currentTreeNode->number);
            // move currentTreeNode to its right child
            currentTreeNode = currentTreeNode->right;
        }
        
    }
    
}
