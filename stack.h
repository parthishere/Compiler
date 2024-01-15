/**
 * @file    stack.h
 * @brief
 *
 *
 * @author  Parth Thakkar
 * @date    20th Sept 2023
 *
 */

#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define DEBUG_PRINT 0

#if DEBUG_PRINT == 1
#define logPrint printf 
#else
#define logPrint(...) 
#endif

typedef struct{
    int * buffer;
    int max_size;
    int current_size;
}stack_t;

typedef enum {
    ERROR=-1,
    VALID=1 
}error_code_t;

stack_t * createStack(uint8_t size);
void deleteStack(stack_t * stack_instance);

int pushStack(stack_t * stack_instance, int data);
error_code_t popStack(stack_t * stack_instance, int * data);

error_code_t topElement(stack_t * stack_instance, int * data);
void printStack(stack_t * stack_instance);
error_code_t notEmptyStack(stack_t *stack_instance);


#endif // !__STACK_H__