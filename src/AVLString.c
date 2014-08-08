#include "AVLString.h"
#include <String.h>
#include "AVL.h"
#include "StringObject.h"
#include "Text.h"
/**
* Function  : compare the String and return for the similarity(compareString)
* Input     : two different string to compare
* Return    : if same return 0, if bigger than 0 return 1, if smaller than 0 return -1
*/
int compareString(void *nodeInTree, void *nodeToCompare){
	NodeString *node1 = (NodeString *)nodeInTree;
	NodeString *node2 = (NodeString *)nodeToCompare;
	
	if(strcmp(node1->string, node2->string) == 0)return 0;
	else if(strcmp(node1->string, node2->string) > 0) return 1;
	else if(strcmp(node1->string, node2->string) < 0) return -1;

}
/**
* Function  : AVL Find for the node in the AVL tree (avlFind2) with pointer to pointer root
* Input     : the root of tree and the element to Find in the tree
* Return    : element To find (found)
*/
Node *avlFind(Node **root, void *elementToFind, int(*compare)(void *,void *)){
  Node *temp = NULL;
  Node *rootFind = *root;
  
  if(*root == NULL || elementToFind == NULL) return NULL;
  else{
  int compareResult = compare(*root,elementToFind);
  
  if(compareResult == 0){ temp = *root;}
  else if(compareResult == -1){temp = avlFind(&rootFind->rightChild,elementToFind,compare);}
  else if(compareResult == 1){temp = avlFind(&rootFind->leftChild,elementToFind,compare);}
  return temp;

  }
}
/**
* Function  : AVL Find for the node in the AVL tree (avlFind2)
* Input     : the root of tree and the element to Find in the tree
* Return    : element To find (found)
*/
Node *avlFind2(Node *root, void *elementToFind, int(*compare)(void *,void *)){ //without pointer to pointer
	Node *temp=NULL;
  
	if(root == NULL || elementToFind == NULL) return NULL;
  else{
	int compareResult = compare(root,elementToFind);
  
	if(compareResult == 0){	temp = root;}
	else if (compareResult == -1){temp = avlFind2(root->rightChild,elementToFind,compare);}
	else if (compareResult == 1){temp = avlFind2(root->leftChild,elementToFind,compare);}
	return temp;
  }
}