/**
 * @file    math_decode.h
 * @brief
 *
 *
 * @author  Parth Thakkar
 * @date    20th Sept 2023
 *
 */

#ifndef __MATH_DECODE_H__
#define __MATH_DECODE_H__

#include <stdio.h>
#include <stdint.h>
#include "parenthesis.h"
#include <math.h>


void covertInfixToPostfix(char* expression, char * postFixExpr);
void parsePostfix(char * expression);

#endif // !__MATH_DECODE_H__