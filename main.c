#include <stdio.h>
#include "math_decode.h"
#include "parenthesis.h"
#include "stack.h"
#include "assert.h"



int main(){
    stack_t * stack1 = createStack(10);
    int popElement;

    assert(pushStack(stack1, 1) == 1);
    printStack(stack1);


    assert(pushStack(stack1, 2) == 2);
    

    printf("popped element: %d", popStack(stack1, &popElement));
    printStack(stack1);

    assert(pushStack(stack1, 2) == 2);
    assert(pushStack(stack1, 3) == 3);
    assert(pushStack(stack1, 4) == 4);
    assert(pushStack(stack1, 5) == 5);
    assert(pushStack(stack1, 6) == 6);
    assert(pushStack(stack1, 7) == 7);
    assert(pushStack(stack1, 8) == 8);
    assert(pushStack(stack1, 9) == 9);
    assert(pushStack(stack1, 0) == 0);
    printStack(stack1);

    printf("Popped element: %d\n", popStack(stack1, &popElement));
    printf("Popped element: %d\n", popStack(stack1, &popElement));
    printf("Popped element: %d\n", popStack(stack1, &popElement));
    printf("Popped element: %d\n", popStack(stack1, &popElement));
    printf("Popped element: %d\n", popStack(stack1, &popElement));
    printf("Popped element: %d\n", popStack(stack1, &popElement));
    printf("Popped element: %d\n", popStack(stack1, &popElement));
    printf("Popped element: %d\n", popStack(stack1, &popElement));
    printf("Popped element: %d\n", popStack(stack1, &popElement));
    printf("Popped element: %d\n", popStack(stack1, &popElement));


    printf("popped element: %d", popStack(stack1, &popElement));    
    printStack(stack1);





    char * expr1 = "{()}";
    char * expr2 = "([{}])";
    char * expr3 = "({)}";
    char * expr4 = "}()";
    char * expr5 = "{}";

    printf("is valid or not : %d\n", checkParenthesis(expr1));
    printf("is valid or not : %d\n", checkParenthesis(expr2));
    printf("is valid or not : %d\n", checkParenthesis(expr3));
    printf("is valid or not : %d\n", checkParenthesis(expr4));

    printf("is valid or not : %d\n", checkParenthesis(expr5));



    char infix[] = "29+3+4-50*6-1\0";
    char infix1[] = "2+3-(43+5)*6\0";
    char infix2[] = "1-2-3-44-5\0";
    char infix3[] = "1000+2000*3000\0";
    char infix4[] = "10+{12+13*(14-15)}-2\0";
    char postfix[300];


    printf("\nInfix expression: %s\n", infix);
    covertInfixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    parsePostfix(postfix);

    printf("\nInfix expression: %s\n", infix1);
    covertInfixToPostfix(infix1, postfix);
    printf("Postfix expression: %s\n", postfix);
    parsePostfix(postfix);

    printf("\nInfix expression: %s\n", infix2);
    covertInfixToPostfix(infix2, postfix);
    printf("Postfix expression: %s\n", postfix);
    parsePostfix(postfix);

    printf("\nInfix expression: %s\n", infix3);
    covertInfixToPostfix(infix3, postfix);
    printf("Postfix expression: %s\n", postfix);
    parsePostfix(postfix);

    printf("\nInfix expression: %s\n", infix4);
    covertInfixToPostfix(infix4, postfix);
    printf("Postfix expression: %s\n", postfix);
    parsePostfix(postfix);

    

    return 0;
}