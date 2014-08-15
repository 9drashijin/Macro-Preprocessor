#ifndef AVLString_H
#define AVLString_H

#include "AVL.h"
#include "StringObject.h"
#include "Text.h"


typedef struct NodeString NodeString;
typedef struct DefinitionTable DefinitionTable;

struct NodeString{
	int balance;
	NodeString *leftChild;
  NodeString *rightChild;
	char *string;
};

struct DefinitionTable{
  int balance;
  DefinitionTable *leftChild;
  DefinitionTable *rightChild;
  void *data;
};

#define avlAddString(root, nodeToAdd) avlAdd((Node *)(root) , (Node *)(nodeToAdd) , compareString)

#define avlFindString(root, elementToFind) (NodeString*)avlFind((Node *)(root) , (Node *)(elementToFind) , compareString)
#define avlFindString2(root, elementToFind) (NodeString*)avlFind2((Node *)(root) , (Node *)(elementToFind) , compareString)

#define avlFindDef(root, elementToFind) (DefinitionTable*)avlFind((Node *)(root) , (Node *)(elementToFind) , compareString)
#define avlFindDef2(root, elementToFind) (DefinitionTable*)avlFind2((Node *)(root) , (Node *)(elementToFind) , compareString)


int compareString(void *nodeInTree, void *nodeToCompare);
Node *avlFind(Node **root, void *elementToFind, int(*compare)(void *,void *));  
Node *avlFind2(Node *root, void *elementToFind, int(*compare)(void *,void *)); //without pointer to pointer root  
//using avlFind2

#endif // AVLString_H
