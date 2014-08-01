#include "Definition.h"
#include <malloc.h>
#include "ErrorCode.h"
#include "CException.h"
#include <string.h>
#include <stdio.h>
#include "StringObject.h"
#include "Text.h"


Definition *addDefinition(String *name, String *content){
	Definition *define = malloc(sizeof(Definition));
	
	define->name = name;
	define->content = content;
	
	return define;
}

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
/**
  //  2+3*MIN-6/8
  //  0123456789
  //  0 ~ 3 store to temp + 3 (7 ~ 10 store to another)
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

void strCpy(char *dest, char *src, int start, int length){
  int i,j;
  
  for(i = start, j = 0; i<length; i++, j++){
    dest[j] = src[i];
  }
  dest[j] = 0;
  
}
