#include <stdio.h>
#include "math_decode.h"
#include "parenthesis.h"
#include "stack.h"
#include "assert.h"



int main(){

    char infix[] = "10+{12+13*(14-15)}-2\0";
    char postfix[300];
    covertInfixToPostfix(infix, postfix);
    printf("Infix expression: %s\n", infix);

    printf("Postfix expression: %s\n", postfix);

    

    return 0;
}