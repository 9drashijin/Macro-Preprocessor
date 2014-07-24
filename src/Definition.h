#ifndef Definition_H
#define Definition_H

#include "StringObject.h"

typedef struct {
	//TokenType type;
	char name;
	char content;
}Definition;

Definition *createDefinition(char *name, char *conetent);

#endif // Definition_H
