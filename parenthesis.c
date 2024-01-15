/**
 * @file    parenthesis.c
 * @brief
 *
 *
 * @author  Parth Thakkar
 * @date    20th Sept 2023
 *
 */

#include "parenthesis.h"

/*
 * Function: checkParenthesis
 * --------------------------
 * Description: Checks if the parentheses, brackets, and braces in an expression are correctly balanced.
 *              The function iterates through each character of the expression, using a stack
 *              to track opening parentheses/brackets/braces and ensure they are properly closed.
 *
 * Parameters:
 *   expr - Pointer to the expression string to be checked.
 *
 * Returns:
 *   VALID if the parentheses/brackets/braces are balanced, ERROR otherwise.
 */
error_code_t checkParenthesis(char *expr)
{
    char *temp = expr;

    int length_of_expression = 0;
    // Calculate the length of the expression
    while (*temp != '\0')
    {
        length_of_expression++;
        temp++;
    }

    stack_t *stack_for_expression = createStack(length_of_expression);
    // Calculate the length of the expression
    while (*expr != '\0')
    {
        // Calculate the length of the expression
        if (*expr == '}' || *expr == ']' || *expr == ')')
        {
            int bracket;
            error_code_t error_type = popStack(stack_for_expression, &bracket);

            // If the stack is empty (no matching opening bracket), return error
            if (error_type == ERROR)
            {
                printf("Started Braces with closed braces, Pair not found ! \n");
                deleteStack(stack_for_expression);
                return ERROR;
            }

            // Check if the popped bracket matches the current closing bracket
            if (bracket != ((*expr) - 2) && bracket != ((*expr) - 1))
            {
                printf("Braces sequence is not correct !\n");
                deleteStack(stack_for_expression);
                return ERROR;
            }
        }

        // Push opening parentheses/brackets/braces onto the stack
        else if (*expr == '{' || *expr == '[' || *expr == '(')
        {
            pushStack(stack_for_expression, *expr);
        }

        expr++; // Move to the next character
    }

    // If the stack is not empty after processing the entire expression, return Error


    if (notEmptyStack(stack_for_expression) == ERROR){
        deleteStack(stack_for_expression);
        return VALID;
    }
        
    deleteStack(stack_for_expression);
    return ERROR;// Unbalanced braces found
}