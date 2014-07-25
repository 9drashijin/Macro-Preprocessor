#ifndef Text_H
#define Text_H

#define t (Text *)"\x00\x00\x00\x80"

typedef struct Text{
	int reference;
	char string[0];
}Text;

Text *textNew(char *CharStr);
Text *textAssign(Text *text);
Text *textDelete(Text *text);


#endif // Text_H
