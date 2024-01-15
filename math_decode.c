#include "math_decode.h"


int isOperand(char ch){
    return (ch >= 48 && ch <= 57);
}

int isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%');
}

int isClosingBracket(char ch){
    return (ch == '}' || ch == ')' || ch == ']' );
}

int isOpeningBracket(char ch){
    return (ch == '(' || ch == '{' || ch == '[' );
}

// void remove_spaces(char* s) {
//     char* d = s;
//     do {
//         while (*d == ' ') {
//             ++d;
//         }
//     } while (*s++ = *d++);
// }

int is_delimiter(char c, const char delimiter)
{
    return (c == delimiter || c == '\0');
}

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

void covertInfixToPostfix(char* expression, char * postFixExpr) 
{ 
 
    if(checkParenthesis(expression) == ERROR){
        return;
    }
    
    // remove_spaces(expression);

    int postFixExprIndex = 0;
    stack_t * stack = createStack(50);

    while(*expression != '\0'){
        while(isOperand(*expression)){
            postFixExpr[postFixExprIndex] = *expression;
            postFixExprIndex++;
            expression++;
            if(!isOperand(*expression)){
                postFixExpr[postFixExprIndex] = ',';
                postFixExprIndex++;
            }
        }
        
        if(*expression == '(' || *expression == '{' || *expression == '[' ){
            pushStack(stack, *expression);
        }
        else if(*expression == '}' || *expression == ']' || *expression == ')' ){
            
            int popping_bracket;
            topElement(stack, &popping_bracket);
           
            while(1){
                popStack(stack, &popping_bracket) ;
                if(isOpeningBracket(popping_bracket)){
                    break;
                }
                postFixExpr[postFixExprIndex] = popping_bracket;
                postFixExprIndex++;
                postFixExpr[postFixExprIndex] = ',';
                postFixExprIndex++;
            }
            
        }
        else {
            int top_element;
            topElement(stack, &top_element);
            while (precedence(top_element) >= precedence(*expression)) {
                if (popStack(stack, &top_element) == VALID){
                    postFixExpr[postFixExprIndex] = top_element;
                    postFixExprIndex++;
                    postFixExpr[postFixExprIndex] = ',';
                    postFixExprIndex++;
                }
                else{
                    break;
                }
               
            }
            pushStack(stack, *expression);
        }

        expression++;
    }
    int top_element;

    while(topElement(stack, &top_element) == VALID){
        popStack(stack, &top_element);
        postFixExpr[postFixExprIndex] = top_element;
        postFixExprIndex++;
    }
    // postFixExpr[postFixExprIndex-2] = '\0';
    postFixExpr[postFixExprIndex] = '\0';

    

    deleteStack(stack);
} 



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
                int op1, op2, result;
                printf("parsed operator %c\n", expression[start]);

                if (popStack(stack, &op1) == ERROR) break;
                if (popStack(stack, &op2) == ERROR) break;

                switch(expression[start]){
                    case '+':
                        result = op1 + op2;
                        break;
                    case '-':
                        result = op2 - op1;
                        break;
                    case '*':
                        result = op1 * op2;
                        break;
                    case '/':
                        result = op1 / op2;
                        break;
                    case '^':
                        result = op1 ^ op2;
                        break;
                    default:
                        result = 0;
                }

                pushStack(stack, result);
            }
            else{
                // Decode a decimal number
                int temp_number = parse_decimal(&expression[start], length);
                printf("parsed number or parsed char : %d\n", temp_number);
                pushStack(stack, temp_number);
            }
            
             
            start = -1; // Reset 'start' for the next number
        }

        index++; // Move to the next character
    }

    int result;
    popStack(stack, &result);
    printf("final answer is %d \n", result);

    
    deleteStack(stack);
}