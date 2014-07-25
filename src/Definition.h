#ifndef Definition_H
#define Definition_H

#include "StringObject.h"
#include "Text.h"
#include "Token.h"

typedef struct Definition{
	TokenType type;
	String *name;
	String *content;
}Definition;

Definition *addDefinition(String *name, String *content);
int isPreprocessors(Text *hash);
void defineTest(String *define);
Text *textClone(String *str);
Text *textSubstitude(Text *text, int relativeStart, int length, Text *subText);

#endif // Definition_H
