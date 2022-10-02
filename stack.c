/*******************************************************************************************
* File Name          : stack.c
* Description        : Prog8130 - Assignment 3: Stack
*                      This program should implement a stack to push/pop a list of
*                      positive numbers
*
* Author:              Gaurav Kalia
* Date:                26th March, 2022
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure used for holding data
typedef struct node {
    int number;
    struct node *next;
} Node;

// stack top
Node *top = NULL;

// stack functions
void push(const int number);
int pop();

int main(int argc, char *argv[]) {
        int number;             // to store new number
        int i;                  // used in for loop as index

        // put all the numbers into the binary tree
        // numbers will be provided from command line
        for (i = 1; i < argc; i++) {
            // if it is a pop operation
            if (!strcmp(argv[i], "pop")) {
                printf("%s ", argv[i]);
                printf("%d\n", pop(top));
            } else {
                number = atoi(argv[i]);
                printf("push %d\n", number);
                push(number);
            }
        }
        return 0;
}

//====================== You should not modify anything above ==============================//
//==================== You should only modify following functions ==========================//
//============================= do not remove above comments  ==============================//

// FUNCTION      : push
//
// DESCRIPTION   :
//   This function will push a new number into a stack
//
// PARAMETERS    :
//   number - the number that is to be stored in the stack
//
// RETURNS       :
//   Nothing
void push(const int number) {
    // your code
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->number = number;
    newNode->next = NULL;

    if (top == NULL)
    {
        /* code */
        newNode->next = NULL;
        top = newNode;
    }
    else{
        newNode->next = top;
        top = newNode;
    }
    
}

// FUNCTION      : pop
//
// DESCRIPTION   :
//   This function will pop a number from a stack
//
// PARAMETERS    :
//   None
//
// RETURNS       :
//   the number poped or -1 if the stack is empty
int pop() {
    // your code

    Node *ptr = top;
    if (top == NULL)
    {
        /* code */
        return -1;
    }
    else{
        top = top->next;
        return ptr->number;
    }
    
}

