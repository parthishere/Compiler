/**
 * @file    stack.h
 * @brief   Header file for stack operations.
 *
 *          This file declares the structure for a stack and associated functions 
 *          for performing various stack operations. It includes dependencies 
 *          for standard libraries and defines a macro for debug printing.
 *
 * @author  Parth Thakkar
 * @date    14th Jan 2024
 *
 */

#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Macro for enabling or disabling debug print statements
#define DEBUG_PRINT 0

#if DEBUG_PRINT == 1
#define logPrint printf  // Enable logging if DEBUG_PRINT is set to 1
#else
#define logPrint(...)    // Disable logging
#endif

// Struct for representing a stack
typedef struct {
    int *buffer;        // Pointer to the stack's buffer (array of integers)
    int max_size;       // Maximum size of the stack
    int current_size;   // Current number of elements in the stack
} stack_t;

// Enum for representing error codes
typedef enum {
    ERROR = -1,  // Error code for failure conditions
    VALID = 1    // Code indicating successful operation
} error_code_t;

/**
 * @brief Creates and initializes a new stack.
 * 
 * @param size The maximum size of the stack.
 * @return stack_t* Pointer to the newly created stack instance.
 *
 * Allocates memory for a new stack and its internal buffer. Initializes 
 * the stack properties and sets all buffer elements to zero.
 */
stack_t *createStack(uint8_t size);


/**
 * @brief Frees the memory allocated for a stack and its buffer.
 * 
 * @param stack_instance Pointer to the stack instance to be deleted.
 * @return void
 *
 * Safely deallocates the memory used by the stack and its buffer, 
 * ensuring no memory leaks occur.
 */
void deleteStack(stack_t * stack_instance);


/**
 * @brief Pushes a new element onto the stack.
 *
 * @param stack_instance Pointer to the stack where the data will be pushed.
 * @param data The data (integer) to be pushed onto the stack.
 * @return int The data pushed onto the stack, or ERROR if the stack is full.
 * 
 * Adds a new element to the top of the stack. If the stack is at its maximum
 * capacity, logs an overflow error and returns ERROR.
*/
int pushStack(stack_t * stack_instance, int data);

/**
 * 
 * @brief Pops the top element from the stack.
 * 
 * @param stack_instance Pointer to the stack from which the data will be popped.
 * @param data Pointer to store the popped data.
 * @return error_code_t VALID if the operation is successful, ERROR if the stack is empty.
 * 
 * Removes and returns the top element of the stack. If the stack is empty,
 * logs an underflow error and returns ERROR.
*/
error_code_t popStack(stack_t * stack_instance, int * data);


/**
 * 
 * @brief Retrieves the top element of the stack without removing it.
 * 
 * @param stack_instance Pointer to the stack.
 * @param data Pointer to store the top element.
 * @return error_code_t VALID if the stack is not empty, ERROR otherwise.
 * 
 * Peeks at the top element of the stack without modifying the stack's state.
 * If the stack is empty, logs an error and returns ERROR.
*/
error_code_t topElement(stack_t * stack_instance, int * data);


/**
 * 
 * @brief Prints the contents of the stack.
 * 
 * @param stack_instance Pointer to the stack to be printed.
 * @return void
 * Iterates through the stack and prints each element along with its index.
 * 
 * Useful for debugging and visualizing the stack's state.
*/
void printStack(stack_t * stack_instance);


/**
 * 
 * @brief Checks if the stack is not empty.
 * 
 * @param stack_instance Pointer to the stack to be checked.
 * @return error_code_t VALID if the stack is not empty, ERROR otherwise.
 * 
 * Determines if the stack contains any elements. Returns VALID if not empty,
 * and ERROR if empty.
*/
error_code_t notEmptyStack(stack_t *stack_instance);


#endif // !__STACK_H__