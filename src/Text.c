#include "Text.h"
#include <stdio.h>
#include <malloc.h>
#include "String.h"

Text *textNew(char *str){
	Text *text = (Text *)malloc(strlen(str)+4+1);
	strcpy(text->string,str);
	text->reference = 1;
	return text;
}

Text *textAssign(Text *text){
	if(text->reference < 0x80000000)
		text->reference++;
	return text;
}

Text *textDelete(Text *text){
	if(text->reference < 0x80000000 && text->reference > 0){
		text->reference--;
		if(text->reference == 0){
			free(text);
			return NULL;
		}		
	}
	return text;
}