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

Text *textSubstitude(Text *text, int relativeStart, int length, Text *subText){
  
  
  
  
}