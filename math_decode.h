/**
 * @file    math_decode.h
 * @brief   Header file for mathematical expression decoding functions.
 *
 *          This file declares functions for converting infix mathematical 
 *          expressions to postfix notation and for parsing these postfix 
 *          expressions.
 *
 * @author  Parth Thakkar
 * @date    14th Jan 2024
 *
 */

#ifndef __MATH_DECODE_H__
#define __MATH_DECODE_H__

#include <stdio.h>
#include <stdint.h>
#include "parenthesis.h"
#include <math.h>

/**
 * @brief Converts an infix expression to a postfix expression.
 * 
 * @param expression Char array representing the infix expression.
 * @param postFixExpr Char array where the converted postfix expression will be stored.
 * @return void
 *
 * This function takes an infix mathematical expression and converts it
 * to postfix notation for easier evaluation. The conversion process 
 * involves handling operators and parentheses to ensure correct 
 * precedence and associativity.
 */
void covertInfixToPostfix(char* expression, char * postFixExpr);

/**
 * @brief Parses and evaluates a postfix expression.
 * 
 * @param expression Char array representing the postfix expression.
 * @return void
 *
 * This function takes a postfix mathematical expression and evaluates it.
 * The evaluation is performed using a stack to handle the operands and 
 * operators in the postfix expression. The final result of the expression 
 * is printed to the console.
 */
void parsePostfix(char * expression);

#endif // !__MATH_DECODE_H__