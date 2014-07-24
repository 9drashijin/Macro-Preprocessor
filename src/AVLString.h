#ifndef AVLString_H
#define AVLString_H

#include "AVL.h"

typedef struct NodeString NodeString;

struct NodeString{
	int balance;
	NodeString *leftChild;
    NodeString *rightChild;
	char *string;
};

#define avlAddString(root, nodeToAdd) avlAdd((Node *)(root) , (Node *)(nodeToAdd) , compareString)

int compareString(void *nodeInTree, void *nodeToCompare);

#endif // AVLString_H
