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

Definition *definitionFind(DefinitionTable tbl, String *name){}
void DefinitionAdd(DefinitionTable *tbl, Definition *definition){}











