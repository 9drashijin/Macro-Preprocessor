#include "Definition.h"
#include <malloc.h>
#include "ErrorCode.h"
#include "CException.h"
#include <string.h>
#include <stdio.h>

Definition *addDefinition(String *name, String *content){
	Definition *define = malloc(sizeof(Definition));
	
	define->name = *name;
	define->content = *content;
	
	return define;
}

int isPreprocessor(char hash){
	if(hash == '#')
		return 1;
	else
		Throw(ERROR_NOT_DEFINE);
		printf("zxc");
}