#ifndef Definition_H
#define Definition_H

#include "StringObject.h"

typedef struct {
	//TokenType type;
	String name;
	String content;
}Definition;

Definition *addDefinition(String *name, String *content);
int isPreprocessor(char hash);

#endif // Definition_H
