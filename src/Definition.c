#include "Definition.h"
#include <malloc.h>
#include "ErrorCode.h"
#include "CException.h"
#include <string.h>
#include <stdio.h>
#include "StringObject.h"
#include "Text.h"
#include "CharSet.h"
#include "AVLString.h"
#include "AVL.h"
#include "Rotation.h"

/**
* Function  : Add Definition for the test with the name and its content (addDefinition)
* Input     : the Definition Name and the Definition content
* Return    : return the name and content for the new Definition
*/
Definition *addDefinition(String *name, String *content){
	Definition *define = malloc(sizeof(Definition));

	define->name = name;
	define->content = content;

	return define;
}
/**
* Function  : Checking for the String weather it is a Preprocessor with #define or doesn't(isPreprocessors)
* Input     : The text to be tested for its Preprocessor availability
* Return    : if the text is a Preprocessor return 1, else Throw ERROR
*/
int isPreprocessors(Text *hash){
  Text *define = textNew("#define");
	if(strcmp(hash->string,define->string)==0)
		return 1;
	else
		Throw(ERROR_NOT_DEFINE);
}

/**
* Function  : Clone the Text to the another text destination (textClone)
* Input     : The text to be clone;
* Return    : The Cloned new text
*/
Text *textClone(Text *text){
  Text *clonetxt = malloc(strlen(text->string)+4+1);

	strcpy(clonetxt->string,text->string);
	clonetxt->reference = 1;

	return clonetxt;
}

/**   EXAMPLE
  //  2+3*MIN-6/8
  //  0123456789
  //  0 ~ 3 store to temp + 3 (7 ~ 10 store to another)
  //  2+3*(3-4)-6/8
  */
/**
* Function  : substitute the text for the replacement of the text with the subText(textSubstitute)
* Input     : The main text, and its relativeStrart and length for the SubText
* Return    : return the Text after substitute with the subText
*/
Text *textSubstitute(Text *text, int relativeStart, int length, Text *subText){
  Text *Temp;
  int txtLength, subLength, returnLength ,storedLength;
  int cpyStart,cpyLength;

  txtLength = textLength(text);
  subLength = textLength(subText);
  returnLength = txtLength + subLength - length;
  // printf("returnLength: %d \n",returnLength);

  Text *Textreturn = textEmptyNew(returnLength);
  strncpy(Textreturn->string,text->string,relativeStart);

  // printf("string Store front    : %s\n", Textreturn->string);

  storedLength = textLength(Textreturn);
  strcat(Textreturn->string,subText->string);

  // printf("string Append replace : %s\n\n", Textreturn->string);

  cpyStart = storedLength+length;
  cpyLength = txtLength - cpyStart;

  strcpy(Temp->string,&text->string[cpyStart]);
  strcat(Textreturn->string,Temp->string);

  return Textreturn;
}
/**
* Function  : Custom string Copy (strCpy)
* Input     : Source and Destination with start and the length of the string to copy
* Output    : none
*/
void strCpy(char *dest, char *src, int start, int length){
  int i,j;

  for(i = start, j = 0; i<length; i++, j++){
    dest[j] = src[i];
  }
  dest[j] = 0;
}

Definition *DefinitionFind(DefinitionTable *tbl, String *name){} //macro
void DefinitionAdd(DefinitionTable *tbl, Definition *definition){} //macro

//MAX->MIN->ULTRA->MAX
//max min123
//min ultra123
//ultra max123

/**
* Function  : check for cyclic error if define A content the define B while define B also content define A(cyclicCheck)
* Input     : two different Definition to check and compare
* Return    : if there are no error return 1
*             if error occurs its throw ERROR_CYCLIC_OCCUR
*/
int cyclicCheck(Definition *define1, Definition *define2){ //def1 content def2 name == def1 name def2 content
  if(strcmp(define1->content->text->string,define2->name->text->string)==strcmp(define1->name->text->string,define2->content->text->string))
		Throw(ERROR_CYCLIC_OCCUR);
	else
		return 1;
}

int cyclicCheck2(Definition *define1, Definition *define2, Definition *define3){ //def1 content def2 name == def1 name def2 content
  if((strcmp(define1->content->text->string,define2->name->text->string)==strcmp(define1->name->text->string,define2->content->text->string))==(strcmp(define2->content->text->string,define3->name->text->string)==strcmp(define2->name->text->string,define3->content->text->string)))
		Throw(ERROR_CYCLIC_OCCUR);
	else
		return 1;
}

/**
* Function  : compare the node is Equal or not and return for the similarity(compareDefinition)
* Input     : two different node to compare
* Return    : if same return 0, if bigger than 0 return 1, if smaller than 0 return -1
*/
int compareDefinition(void *nodeInTree, void *stringToCompare){
	DefinitionTable *node1 = (DefinitionTable *)nodeInTree;
  DefinitionTable *node2 = (DefinitionTable *)stringToCompare;

  if(stringIsEqual(node1->data, node2->data) == 0)return 0;
	else if(stringIsEqual(node1->data, node2->data) > 0) return 1;
	else if(stringIsEqual(node1->data, node2->data) < 0) return -1;
}
//DefinitionTable -> Definition -> String -> Text -> char string









