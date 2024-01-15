/**
 * @file    parenthesis.h
 * @brief   Header file for parenthesis checking in mathematical expressions.
 *
 *          This file declares the function for checking the balance and correct
 *          sequence of parentheses in mathematical expressions.
 * 
 * @author  Parth Thakkar
 * @date    14th Jan 2024
 *
 */

#ifndef __PARANTHESIS_H__
#define __PARANTHESIS_H__

#include <stdio.h>
#include <stdint.h>
#include "stack.h"


/**
 * @brief Checks if the parentheses in a given expression are balanced and correctly sequenced.
 * 
 * @param expr Char array representing the mathematical expression to be checked.
 * @return error_code_t Returns VALID if the expression's parentheses are correctly balanced,
 *                      ERROR otherwise.
 *
 * This function iterates through the expression to ensure all types of parentheses
 * (round, square, curly) are correctly opened and closed in pairs, maintaining the 
 * balance and sequence. It uses a stack to track the opening and closing of parentheses.
 */
error_code_t checkParenthesis(char * expr);

#endif // !__PARANTHESIS_H__
