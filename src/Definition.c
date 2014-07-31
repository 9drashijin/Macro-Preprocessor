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
  
Text *textSubstitude(Text *text, int relativeStart, int length, Text *subText){
  int i = 0;
  int lengthText = 0;
  
  Text *Temp = textNew("");
  
  strncpy(Temp->string,text->string,relativeStart);
  i = strlen(Temp->string);
  i = i + length;
  lengthText = strlen(text ->string);
  lengthText = lengthText - i;
  
  // printf("lenght i : %d\n", i);
  // printf("lengthText : %d\n", lengthText);
  // printf("string Store front    : %s\n\n", Temp->string);
  strcat(Temp->string,subText->string);
  // printf("string Append replace : %s\n\n", Temp->string);
  
  // strcat(Temp->string,text->string);
  // printf("string Append back    : %s\n\n", Temp->string);
  
  return Temp;
}