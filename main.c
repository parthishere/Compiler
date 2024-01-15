/**
 * @file    main.c
 * @brief
 *
 *
 * @author  Parth Thakkar
 * @date    20th Sept 2023
 *
 */

#include <stdio.h>
#include "math_decode.h"
#include "parenthesis.h"
#include "stack.h"
#include "assert.h"


// Entry point of the program
int main(){
    // Create a stack with a capacity of 10 elements.
    stack_t *stack1 = createStack(10);
    int popElement; // Variable to store the element popped from the stack.

    // Push elements onto the stack and assert their successful placement.
    // Assert that pushing 1 onto the stack returns 1, indicating success.
    assert(pushStack(stack1, 1) == 1);
    assert(pushStack(stack1, 1) == 1);
    // Print the current state of the stack contents.
    printStack(stack1);


    assert(pushStack(stack1, 2) == 2);
    
    // Pop an element from the stack, print the popped element, and then print the stack's state.
    printf("popped element: %d", popStack(stack1, &popElement));
    printStack(stack1);

    // Push a series of elements onto the stack, each time asserting successful placement.
    // This demonstrates how the stack can store a sequence of integers.
    assert(pushStack(stack1, 2) == 2);
    assert(pushStack(stack1, 3) == 3);
    assert(pushStack(stack1, 4) == 4);
    assert(pushStack(stack1, 5) == 5);
    assert(pushStack(stack1, 6) == 6);
    assert(pushStack(stack1, 7) == 7);
    assert(pushStack(stack1, 8) == 8);
    assert(pushStack(stack1, 9) == 9);

    // Stack overflow
    assert(pushStack(stack1, 0) == -1);

    
    printStack(stack1);

    // Sequentially pop and print multiple elements from the stack.
    // This loop demonstrates the LIFO (Last-In-First-Out) nature of the stack.
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

    // Empty stack
    printf("popped element: %d", popStack(stack1, &popElement));  
    // Print the state of the stack after multiple pop operations.  
    printStack(stack1);




    // Define a series of string expressions to check for balanced parentheses.
    // The goal is to validate the syntactical correctness of these expressions.
    char * expr1 = "{()}";
    char * expr2 = "([{}])";
    char * expr3 = "({)}";
    char * expr4 = "}()";
    char * expr5 = "{}";

    // Check and print the validity of the parentheses in each expression.
    printf("expr1 is valid or not : %d\n", checkParenthesis(expr1));
    printf("\nexpr2 is valid or not : %d\n", checkParenthesis(expr2));
    printf("\nexpr3 is valid or not : %d\n", checkParenthesis(expr3));
    printf("\nexpr4 is valid or not : %d\n", checkParenthesis(expr4));

    printf("\nexpr5 is valid or not : %d\n", checkParenthesis(expr5));


    // Define a series of infix expressions to be converted to postfix. and evaluated
    char infix[] = "29+3+4-50*6-1\0"; // -214
    char infix1[] = "2+3-(43+5)*6\0"; // -283
    char infix2[] = "1+(((3*(4/4))^2)%7)-2\0"; // 1
    char infix3[] = "(1000+2000-{3-2*(3/3)})*3000\0"; // 8997000
    char infix4[] = "10+{12+13*(14-15)}-2\0"; // 7
    char infix5[] = "(10+ {12 +13    *(14 -15 ) } - 2)\0"; // 7

    char postfix[300];

     // Convert each infix expression to postfix and evaluate it.
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

    printf("\nInfix expression: %s\n", infix5);
    covertInfixToPostfix(infix5, postfix);
    printf("Postfix expression: %s\n", postfix);
    parsePostfix(postfix);

    

    return 0;
}