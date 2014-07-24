#ifndef Token_H
#define Token_H

typedef enum {
  NULL_TOKEN,
  NUMBER_TOKEN,
  OPERATOR_TOKEN,
  IDENTIFIER_TOKEN
} TokenType;

typedef struct {
  TokenType type;
} Token;

#endif // Token_H
