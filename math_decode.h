#ifndef __MATH_DECODE_H__
#define __MATH_DECODE_H__

#include <stdio.h>
#include <stdint.h>
#include "parenthesis.h"

error_code_t decodeExpression(char * expr, int * value);
void covertInfixToPostfix(char* expression, char * postFixExpr);

#endif // !__MATH_DECODE_H__