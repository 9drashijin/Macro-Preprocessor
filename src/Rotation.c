#include "Rotation.h"
#include <stdio.h>

int getHeight(Node *parent){
  int left=0,right=0;

  if(parent->leftChild == NULL && parent->rightChild == NULL) return 1;
  else if(parent->leftChild == NULL){right = getHeight(parent->rightChild);}
  else if(parent->rightChild == NULL){left = getHeight(parent->leftChild);}
  else{
    left = getHeight(parent->leftChild);
    right = getHeight(parent->rightChild);
    }
    if(left >= right) return left+1;
    else return right+1;
}

// int getbalance(Node *parent){
  // int left=0, right = 0;

  // if(parent == NULL) return 0;
  // else if (parent->leftChild == NULL || parent->rightChild == NULL) return 0;
  // else{
	  // left = getHeight(parent->leftChild);
	  // right = getHeight(parent->rightChild);
	  // return  left - right;
	  // }
// }

Node *rightRotate(Node *parent){

  if(parent->balance == -2 && parent->leftChild->balance == -1){parent->balance = 0; parent->leftChild->balance = 0; }
  else if(parent->balance == -1 && parent->leftChild->balance == -1){parent->balance = 1; parent->leftChild->balance = 1; }
  else if(parent->balance == +1 && parent->leftChild->balance == -1){parent->balance = 2; parent->leftChild->balance = 0; }
  else if(parent->balance == 0 && parent->leftChild->balance == -1 ){parent->balance = 1; parent->leftChild->balance = 0; }
  else if(parent->balance == -2 && parent->leftChild->balance == -2){parent->balance = 0; parent->leftChild->balance = 1; }
  else if(parent->balance == -2 && parent->leftChild->balance ==  0){parent->balance = -1; parent->leftChild->balance = +1; }

  Node *Parent = parent->leftChild;
  parent->leftChild = NULL;

  if(Parent->rightChild!=NULL) parent->leftChild = Parent->rightChild;

  Parent->rightChild = parent;

  // Parent->balance += 1;
  // Parent->rightChild->balance += 2;
  return Parent;
}
Node *leftRotate(Node *parent){

  if(parent->balance == +2 && parent->rightChild->balance == +1){parent->balance = 0; parent->rightChild->balance = 0; }
  else if(parent->balance == +1 && parent->rightChild->balance == +1){parent->balance = -1; parent->rightChild->balance = -1; }
  else if(parent->balance == +1 && parent->rightChild->balance == -1){parent->balance = 0; parent->rightChild->balance = -2; }
  else if(parent->balance == +1 && parent->rightChild->balance == 0 ){parent->balance = 0; parent->rightChild->balance = -1; }
  else if(parent->balance == +2 && parent->rightChild->balance == +2){parent->balance = -1; parent->rightChild->balance = 0; }
  else if(parent->balance == +2 && parent->rightChild->balance == 0){parent->balance = +1; parent->rightChild->balance = -1; }


  Node *Parent = parent->rightChild;
  parent->rightChild = NULL;

  if(Parent->leftChild!=NULL) parent->rightChild = Parent->leftChild;

  Parent->leftChild = parent;

  // Parent->balance += -1;
  // Parent->leftChild->balance += -2;
  return Parent;
}

Node *doubleRightRotate(Node *parent){
  Node *Parent;
  //Node *Parent = parent->leftChild->rightChild;

  // Parent->rightChild = parent;
  // Parent->leftChild = parent->leftChild;

  parent->leftChild = leftRotate(parent->leftChild);
  Parent = rightRotate(parent);

  // Parent->leftChild->balance += -1;
  // Parent->rightChild->balance += 2;
  return Parent;
}
Node *doubleLeftRotate(Node *parent){
  Node *Parent;
  //Node *Parent = parent->rightChild->leftChild;

  // Parent->leftChild = parent;
  // Parent->rightChild = parent->rightChild;

  parent->rightChild = rightRotate(parent->rightChild);
  Parent = leftRotate(parent);

  // Parent->rightChild->balance += 1;
  // Parent->leftChild->balance += -2;
  return Parent;
}

// X test subject
Node *tree(Node *parent){
  Node *Parent = parent->leftChild;

  Parent->leftChild = parent->leftChild->leftChild;
  Parent->rightChild = parent;

  Parent->leftChild->leftChild = parent->leftChild->leftChild->leftChild;
  Parent->rightChild->leftChild = parent->leftChild->rightChild;
  Parent->rightChild->rightChild = parent->rightChild;

  Parent->balance = 2;

  Parent->leftChild->balance = 1;
  Parent->rightChild->balance = 1;

  Parent->leftChild->leftChild = 0;
  Parent->rightChild->leftChild = 0;
  Parent->rightChild->rightChild = 0;

  return Parent;
}
