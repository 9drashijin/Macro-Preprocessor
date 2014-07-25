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
  
  int i = 0;
  int j = strlen(text->string);
  int replace = relativeStart + length;
  int start = text->string[relativeStart];
  int stop = text->string[length];
  
  for(;i<=j;i++){
    if(text->string[i] >= replace ){
    printf("must IN\n");
      for(start;start <= stop ; start++ ){
        printf("must IN to replace\n");
        
        text->string[start] = subText->string[0];
        
        printf("txt %s\n", text->string[start]);
        return text;
        }
    }
    else break;
  }
}