#ifndef Definition_H
#define Definition_H

#include "AVL.h"
#include "StringObject.h"
#include "Text.h"
#include "Token.h"
#include "AVLString.h"
#include "Rotation.h"



typedef struct Definition{
	TokenType type;
	String *name;
	String *content;
}Definition;

#define definitionAdd(tbl, definition) avlAdd((Node *)(tbl) , (Node *)(definition) , compareDefinition)
#define definitionFind(tbl, name) (DefinitionTable*)avlFind2((Node *)(tbl) , (Node *)(name) , compareString)

#define name(node) (((Text *)((String *)((Definition *)(Node1.data))->name)->text)->string)
#define content(node) (((Text *)((String *)((Definition *)(Node1.data))->content)->text)->string)


Definition *addDefinition(String *name, String *content);
int isPreprocessors(Text *hash);
void defineTest(String *define);
Text *textClone(Text *text);
Text *textSubstitute(Text *text, int relativeStart, int length, Text *subText);
void strCpy(char *dest, char *src, int start, int length); //custom stringCopy for word at behind
int cyclicCheck(Definition *define1, Definition *define2);
int cyclicCheck2(Definition *define1, Definition *define2, Definition *define3);

Definition *DefinitionFind(DefinitionTable *tbl, String *name);
void DefinitionAdd(DefinitionTable *tbl, Definition *definition);
int compareDefinition(void *nodeInTree, void *nodeToCompare);

#endif // Definition_H
