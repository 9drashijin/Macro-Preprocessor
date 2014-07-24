#ifndef AVlInt_H
#define AVlInt_H

#include "AVL.h"

typedef struct NodeInt NodeInt;

struct NodeInt{
	int balance;
	NodeInt *leftChild;
  NodeInt *rightChild;
  int data;
};

#define avlAddInt(root, nodeToAdd) avlAdd((Node *)(root) , (Node *)(nodeToAdd) , compareInt)
#define avlRemoveInt(root, nodeToRemove) avlRemove((Node **)(root) , (Node *)(nodeToRemove) , compareInt)

int compareInt(void *nodeInTree, void *nodeToCompare);

#endif // AVlInt_H
