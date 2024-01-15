# Stack Operations and Mathematical Expression Parser

## Overview

This project provides a implementation of stack operations and functions for parsing and evaluating mathematical expressions. The primary focus is on converting infix expressions to postfix notation and evaluating these postfix expressions. The project also includes functionality to check the balance of parentheses in mathematical expressions.

We can perform various operations like +, -, /, %, ^, * with three types of braces like (,(,[. It handles precedence of the operators

### Components

The project consists of several header files, each serving a specific purpose:

- `stack.h`: Defines the structure for a stack and declares functions for stack operations.
- `parenthesis.h`: Declares the function for checking the balance of parentheses in expressions.
- `math_decode.h`: Declares functions for converting infix expressions to postfix and for evaluating postfix expressions.

## Technical and Logical Flow

### Stack Operations

The stack operations are encapsulated within the `stack.h` file. The core functionalities include:

- `createStack(uint8_t size)`: Allocates memory for a new stack with the specified size.
- `deleteStack(stack_t *stack_instance)`: Deallocates the memory assigned to the stack.
- `pushStack(stack_t *stack_instance, int data)`: Adds an element to the top of the stack.
- `popStack(stack_t *stack_instance, int *data)`: Removes and returns the top element from the stack.
- `topElement(stack_t *stack_instance, int *data)`: Retrieves the top element without removing it.
- `printStack(stack_t *stack_instance)`: Prints the current elements in the stack.
- `notEmptyStack(stack_t *stack_instance)`: Checks if the stack is not empty.

### Parenthesis Checking

The `parenthesis.h` file includes the `checkParenthesis(char *expr)` function. This function is crucial for ensuring the syntactical correctness of mathematical expressions. It uses a stack to track each opening parenthesis and matches it with the corresponding closing parenthesis.

### Infix to Postfix Conversion

The `math_decode.h` file declares the `covertInfixToPostfix(char* expression, char *postFixExpr)` function. This function converts an infix expression (where operators are placed between operands) into postfix notation (where operators follow their operands). The function uses the stack structure to handle operators and parentheses, applying the shunting-yard algorithm to ensure correct operator precedence and associativity.

### Postfix Expression Evaluation

Also declared in `math_decode.h`, the `parsePostfix(char *expression)` function evaluates a given postfix expression. This evaluation is done using a stack to temporarily hold operands. When an operator is encountered in the expression, the function applies it to the operands popped from the stack and then pushes the result back onto the stack. The final value at the top of the stack is the result of the expression.

## Usage

To use these functionalities:

1. Include the necessary headers in your main program file.
2. Create a stack using `createStack` and perform operations like pushing or popping elements.
3. For mathematical expressions, first check for balanced parentheses using `checkParenthesis`.
4. Convert infix expressions to postfix using `covertInfixToPostfix`.
5. Evaluate the postfix expressions with `parsePostfix

