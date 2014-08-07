#ifndef AVL_H
#define AVL_H


typedef struct Node Node;

struct Node{
	int balance;
	Node *leftChild;
  Node *rightChild;
  int data;
};

Node *avlAdd(Node *root , Node *nodeToAdd, int (*compare)(void *, void *));
Node *avlRemove(Node **ptrToRoot , Node *nodeToRemove, int (*compare)(void *, void *));
Node *avlGetReplacer(Node **ptrToRoot);
Node *avlRemoveRootName(Node *root);

int compareInt(void *nodeInTree, void *nodeToCompare);

#endif // AVL_H
