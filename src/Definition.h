#ifndef Definition_H
#define Definition_H

#include "StringObject.h"
#include "Text.h"
#include "Token.h"
#include "AVLString.h"
#include "AVL.h"
#include "Rotation.h"



typedef struct Definition{
	TokenType type;
	String *name;
	String *content;
}Definition;

Definition *addDefinition(String *name, String *content);
int isPreprocessors(Text *hash);
void defineTest(String *define);
Text *textClone(Text *text);
Text *textSubstitute(Text *text, int relativeStart, int length, Text *subText);
void strCpy(char *dest, char *src, int start, int length); //custom stringCopy for word at behind
Definition *definitionFind(DefinitionTable tbl, String *name);
void DefinitionAdd(DefinitionTable *tbl, Definition *definition);

#endif // Definition_H
