/**
 * @file    math_decode.c
 * @brief
 *
 *
 * @author  Parth Thakkar
 * @date    20th Sept 2023
 *
 */

#include "math_decode.h"
#include <math.h>

/*
* Function: isOperand
* -------------------
* Description: Checks if the given character is an operand (a number).
*              Operands are identified as ASCII characters ranging from 48 ('0') to 57 ('9').
*
* Parameters:
*   ch - Character to be checked.
*
* Returns: 
*   1 (true) if the character is an operand (a number), 0 (false) otherwise.
*/
int isOperand(char ch){
    return (ch >= 48 && ch <= 57);
}


/*
* Function: isOperator
* --------------------
* Description: Checks if the given character is an operator.
*              Operators are '+', '-', '*', '/', '^', and '%'.
*
* Parameters:
*   ch - Character to be checked.
*
* Returns:
*   1 (true) if the character is an operator, 0 (false) otherwise.
*/
int isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%');
}


/*
* Function: isClosingBracket
* --------------------------
* Description: Checks if the given character is a closing bracket.
*              Closing brackets are '}', ')', and ']'.
*
* Parameters:
*   ch - Character to be checked.
*
* Returns:
*   1 (true) if the character is a closing bracket, 0 (false) otherwise.
*/
int isClosingBracket(char ch){
    return (ch == '}' || ch == ')' || ch == ']' );
}


/*
* Function: isOpeningBracket
* --------------------------
* Description: Checks if the given character is an opening bracket.
*              Opening brackets are '(', '{', and '['.
*
* Parameters:
*   ch - Character to be checked.
*
* Returns:
*   1 (true) if the character is an opening bracket, 0 (false) otherwise.
*/
int isOpeningBracket(char ch){
    return (ch == '(' || ch == '{' || ch == '[' );
}


/*
* Function: removeSpaces
* ----------------------
* Description: Removes all spaces from a given string.
*              The function iterates over each character in the input string,
*              copies non-space characters to a new position in the same string,
*              and null-terminates the resulting string.
*
* Parameters:
*   str - Pointer to the input string from which spaces are to be removed.
*
* Returns:
*   Pointer to the modified input string with spaces removed.
*/
char * removeSpaces(char *str)
{
  char *out = str, *put = str;

  for(; *str != '\0'; ++str)
  {
    if(*str != ' ')
      *put++ = *str; // Copy non-space characters to the new position.
  }
  *put = '\0'; // Null-terminate the modified string.

  return out; // Return the pointer to the modified string.
}


/*
* Function: is_delimiter
* ----------------------
* Description: Checks if a given character is a specific delimiter or the end of a string.
*              Useful for parsing or tokenizing strings.
*
* Parameters:
*   c - The character to be checked.
*   delimiter - The delimiter character against which to check.
*
* Returns:
*   1 (true) if the character is a delimiter or end of string, 0 (false) otherwise.
*/
int is_delimiter(char c, const char delimiter)
{
    return (c == delimiter || c == '\0');
}


/*
* Function: parse_decimal
* -----------------------
* Description: Converts a string of a specific length to a long integer.
*              The function iterates over the string and constructs the integer
*              by parsing each character assumed to be a decimal digit.
*              If a non-decimal character is encountered, an error is returned.
*
* Parameters:
*   str - Pointer to the string to be parsed.
*   length - The number of characters to parse from the string.
*
* Returns:
*   The parsed long integer, or an error if a non-decimal character is encountered.
*/
long parse_decimal(const char *str, int length)
{
    long result = 0; // Initialize result to zero.
    // Loop through each character in the string up to the specified length.
    for (int i = 0; i < length; ++i)
    {
        // If the current character is not a decimal digit, return an error.
        if (str[i] < '0' || str[i] > '9')
        {
            // Handle invalid character
            return (ERROR);
        }
        // Accumulate the result by multiplying by 10 (shifting the decimal place)
        // and adding the integer value of the current digit.
        result = result * 10 + (str[i] - '0');
    }

    return (result); // Return the successfully parsed integer.
}

/*
* Function: precedence
* --------------------
* Description: Determines the precedence of arithmetic operators.
*              The precedence order is '^' > '*'/'/%' > '+'/'-'. 
*              Higher precedence is indicated by a higher return value.
*
* Parameters:
*   ch - The operator character whose precedence is to be determined.
*
* Returns:
*   An integer value representing the precedence level of the operator.
*   Returns -1 if the character is not a recognized operator.
*/
int precedence(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 
    case '%':
    case '*': 
    case '/': 
        return 2; 
    case '^': 
        return 3; 
    } 
    return -1; 
} 


/*
* Function: covertInfixToPostfix
* ------------------------------
* Description: Converts an infix arithmetic expression to postfix notation.
*              The function first checks if the parentheses in the expression are balanced.
*              It then iterates through the expression, applying the shunting-yard algorithm
*              to handle operators and operands, converting the expression to postfix.
*
* Parameters:
*   expression - Pointer to the input infix expression string.
*   postFixExpr - Pointer to the output string where the postfix expression will be stored.
*
* Returns:
*   void
*/
void covertInfixToPostfix(char* expression, char * postFixExpr) 
{ 
 
    // Check if the parentheses in the expression are balanced
    if(checkParenthesis(expression) == ERROR){
        printf("parenthesis not balanced!\n");
        return; // Exit if the parentheses are not balanced
    }
    
    // Remove spaces from the expression for easier processing
    expression = removeSpaces(expression);

    int postFixExprIndex = 0; // Index to keep track of position in postfix expression
    stack_t *stack = createStack(50); // Create a stack to assist in conversion

    // Process each character of the expression
    while(*expression != '\0'){
        // Handle operands (numbers)
        while(isOperand(*expression)){
            postFixExpr[postFixExprIndex++] = *expression++;
            // Separate operands in the postfix expression by commas
            if(!isOperand(*expression)){
                postFixExpr[postFixExprIndex++] = ',';
            }
        }

        // Handle opening brackets by pushing them onto the stack
        if(*expression == '(' || *expression == '{' || *expression == '[' ){
            pushStack(stack, *expression);
        }

        // Handle closing brackets
        else if(*expression == '}' || *expression == ']' || *expression == ')' ){
            
            int popping_bracket;
            topElement(stack, &popping_bracket);

            // Pop elements from the stack until the corresponding opening bracket is found
            while(1){
                popStack(stack, &popping_bracket) ;
                if(isOpeningBracket(popping_bracket)){
                    break;
                }
                postFixExpr[postFixExprIndex] = popping_bracket;
                postFixExprIndex++;
                postFixExpr[postFixExprIndex] = ','; // Add comma separator if more elements are in stack
                postFixExprIndex++;
            }
            
        }
        else {
            // Handle operators
            int top_element;
            topElement(stack, &top_element);
            // Pop operators from the stack with equal or higher precedence
            while (precedence(top_element) >= precedence(*expression)) {
                if (popStack(stack, &top_element) == VALID){
                    postFixExpr[postFixExprIndex] = top_element;
                    postFixExprIndex++;
                    postFixExpr[postFixExprIndex] = ','; // Add comma separator if more elements are in stack
                    postFixExprIndex++;
                }
                else{
                    break;
                }
               
            }
            // Push the current operator onto the stack
            pushStack(stack, *expression);
        }

        expression++; // Move to the next character in the expression
    }
    int top_element;

    // Pop any remaining operators from the stack and add them to the postfix expression
    while(topElement(stack, &top_element) == VALID){
        popStack(stack, &top_element);

        postFixExpr[postFixExprIndex] = top_element;
        postFixExprIndex++;

        postFixExpr[postFixExprIndex] = ','; // Add comma separator if more elements are in stack
        postFixExprIndex++;
    }

    postFixExpr[postFixExprIndex] = '\0'; // Null termination

    

    deleteStack(stack); // Clean up the stack
} 


/*
* Function: parsePostfix
* ----------------------
* Description: Evaluates a postfix expression and prints the result.
*              The function iterates through each character of the postfix expression,
*              decodes numbers and operators, and uses a stack to perform arithmetic operations.
*
* Parameters:
*   expression - Pointer to the postfix expression string to be evaluated.
*
* Returns:
*   void
*/
void parsePostfix(char * expression){
    stack_t * stack = createStack(50);

    int start = -1;     // Start index of the current number being parsed; -1 indicates not currently within a number
    int index = 0;     // Current index in the input string


    while(expression[index] != '\0'){
        if (!is_delimiter(expression[index], ',') && start == -1)
        {
            // If the current character is not a delimiter and we are not already within a number
            start = index; // Set 'start' to the current index
        }

        if (start != -1 && (is_delimiter(expression[index+1], ',') || expression[index+1] == '\0'))
        { // If we are within a number and the next character is a delimiter or the end of the string
            // Found the end of a number
            int length = index - start + 1; // Calculate the length of the current number

            if(isOperator(expression[start])){
                // If the current segment is an operator, perform the corresponding operation
                int op1, op2, result;
                // printf("parsed operator %c\n", expression[start]);

                // Pop two operands from the stack
                if (popStack(stack, &op1) == ERROR) break;
                if (popStack(stack, &op2) == ERROR) break;

                // Perform the operation based on the operator
                switch(expression[start]){
                    case '+':
                        result = op2 + op1;
                        break;
                    case '-':
                        result = op2 - op1;
                        break;
                    case '*':
                        result = op2 * op1;
                        break;
                    case '/':
                        result = op2 / op1;
                        break;
                    case '^':
                        result = pow(op2, op1);
                        break;
                    case '%':
                        result = op2 % op1;
                        break;
                    default:
                        result = 0;
                }
                // Push the result of the operation back onto the stack
                pushStack(stack, result);
            }
            else{
                // Decode a decimal number
                // If the current segment is a number, parse and push it onto the stack
                int temp_number = parse_decimal(&expression[start], length);
                // printf("parsed number or parsed char : %d\n", temp_number);
                pushStack(stack, temp_number);
            }
            
             
            start = -1; // Reset 'start' for the next number
        }

        index++; // Move to the next character
    }

    int result;
    if(popStack(stack, &result) != ERROR) {
        // Pop the final result from the stack and print it
        printf("Final answer is:-> %d \n", result);
    } else {
        printf("Error in expression evaluation.\n");
    }

    
    deleteStack(stack); // Clean up by deleting the stack
}