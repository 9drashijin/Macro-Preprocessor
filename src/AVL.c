#include "AVL.h"
#include "AVLInt.h"
#include "Rotation.h"
#include <stdio.h>

Node *avlAdd(Node *root , Node *nodeToAdd, int (*compare)(void *, void *)){
	int temp=0;
	int compareResult;
	
	if(root == NULL)root = nodeToAdd;
	else{
		
	compareResult = compare(root, nodeToAdd);
	if(compareResult == 0){printf(" ");}
	
	else if (compareResult == 1){ // added left
		
		if(root->leftChild == NULL){
		root->leftChild = avlAdd(root->leftChild,nodeToAdd, compare);
		root->balance += -1;
		}
		else{
		temp = root->leftChild->balance;
		root->leftChild = avlAdd(root->leftChild,nodeToAdd , compare);
		if(root->leftChild->balance!=0 && (root->leftChild->balance - temp) !=0){root->balance += -1;}
		}
		
		if(root->balance == -2){
			if(root->leftChild->balance <= 0){root = rightRotate(root);
			//printf("Rotate Right\n");
			}
			else{root = doubleRightRotate(root);
			//printf("Rotate Right 2 times\n");
			}
		}
	}
	
	else if (compareResult == -1){ //added right
		
		if(root->rightChild == NULL){
		root->rightChild = avlAdd(root->rightChild,nodeToAdd, compare);
		root->balance += 1;
		}
		else{
		temp = root->rightChild->balance;
		root->rightChild = avlAdd(root->rightChild,nodeToAdd, compare);
		if(root->rightChild->balance!=0 && (root->rightChild->balance - temp) !=0){root->balance += 1;}
		}
		
		if(root->balance == 2){
			if(root->rightChild->balance >= 0){root = leftRotate(root);
			//printf("Rotate Left\n");
			}
			else{root = doubleLeftRotate(root);
			//printf("Rotate Left 2 times\n");
			}
		}
	}
	
	else{printf("ZXC");}
}
	
	return root;
}

Node *avlRemove(Node **ptrToRoot , Node *nodeToRemove, int (*compare)(void *, void *)){
  Node *root = *ptrToRoot, temp;
  Node *replace;
	int compareResult;

  if(*ptrToRoot == NULL || nodeToRemove == NULL )return NULL;
  
	else {
	
	compareResult = compare(root, nodeToRemove);
	
  if (compareResult == -1){
    
    nodeToRemove = avlRemove(&root->rightChild,nodeToRemove, compare);
    
    if(root->rightChild != NULL){
      if(root->rightChild->balance == 0) root->balance += -1;
    }
    else{
      if(nodeToRemove != NULL) root->balance += -1;
    }
  }
  
  else if (compareResult == 1){
    
    nodeToRemove = avlRemove(&root->leftChild,nodeToRemove, compare);
    
    if(root->leftChild != NULL){
      if(root->leftChild->balance == 0) root->balance += 1;
    }
    else{
      if(nodeToRemove != NULL) root->balance += 1;
    }
  }
  
  else if (compareResult == 0){
  
	if(root->leftChild != NULL){
	
  replace = avlGetReplacer(&root->leftChild);
	
	root->leftChild = replace;
  root = replace;
	}

  if(root->rightChild !=NULL){
	root = root->rightChild;
  }
  else if(root->leftChild !=NULL){
		if(root->leftChild == NULL) {root->balance +=-1;}
	else if(root->leftChild!=NULL){
		if(root->leftChild->balance ==0){root->balance +=-1;}
	}
	
  }
  else{
	*ptrToRoot = NULL;
  }
  return root;
  }
	
	}
  
  if(root->balance == -2){
			if(root->leftChild->balance <= 0){root = rightRotate(root);
			}
			else{root = doubleRightRotate(root);
			}
		}
  else if(root->balance == 2){
			if(root->rightChild->balance >= 0){root = leftRotate(root);
			}
			else{root = doubleLeftRotate(root);
			}
		}
  
	return nodeToRemove;
}


Node *avlGetReplacer(Node **ptrToRoot){
	Node *rootNode = *ptrToRoot, *replace;

	if(rootNode->rightChild != NULL){
    
		replace = avlGetReplacer( &(*ptrToRoot)->rightChild);

		if(rootNode->rightChild == NULL){
		  (*ptrToRoot)->balance--;
		  // printf("- before\n");
		}
		else {
		  if(rootNode->rightChild->balance ==0)(*ptrToRoot)->balance--;
		  // printf("- after\n");
		}
	}
  else{
  replace = *ptrToRoot;
  if(rootNode->leftChild != NULL){
			*ptrToRoot = (*ptrToRoot)->leftChild;
		}
		else{
			*ptrToRoot = NULL;
      }
  }
  
  if(rootNode->balance == -2){
			if(rootNode->leftChild->balance <= 0){*ptrToRoot = rightRotate(*ptrToRoot);
			}
			else{*ptrToRoot = doubleRightRotate(*ptrToRoot);
			}
		}
  else if(rootNode->balance == 2){
			if(rootNode->rightChild->balance >= 0){*ptrToRoot = leftRotate(*ptrToRoot);
			}
			else{*ptrToRoot = doubleLeftRotate(*ptrToRoot);
			}
		}
	return replace;
	
}

Node *avlRemoveRootName(Node *root){}


Node *avlRemoveX(Node *root , Node *nodeToRemove){return  NULL;}