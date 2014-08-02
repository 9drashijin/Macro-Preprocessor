#ifndef Token_H
#define Token_H

#include "Text.h"
#include "StringObject.h"

typedef enum {
  NULL_TOKEN,
  NUMBER_TOKEN,
  OPERATOR_TOKEN,
  IDENTIFIER_TOKEN
} TokenType;

typedef struct {
  TokenType type;
} Token;

typedef struct {
  TokenType type;
  int value;
} Number;

typedef struct {
  TokenType type;
  Text *name;
  Number *number;
} Identifier;

#endif // Token_H
