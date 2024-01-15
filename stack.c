/**
 * @file    stack.c
 * @brief
 *
 *
 * @author  Parth Thakkar
 * @date    20th Sept 2023
 *
 */

#include "stack.h"


/*
* Function: createStack
* ---------------------
* Description: Allocates memory for a new stack and its buffer, initializing its properties.
*              The function creates a stack with a specified maximum size.
*
* Parameters:
*   max_size - The maximum number of elements the stack can hold.
*
* Returns:
*   A pointer to the newly created stack instance.
*/
stack_t *createStack(uint8_t max_size)
{
    stack_t *stackInstance = (stack_t *)malloc(sizeof(stack_t));

    int *stack_buffer = (int *)malloc((max_size) * sizeof(int));

    if (stack_buffer != NULL)
    {
        stackInstance->buffer = stack_buffer;
        stackInstance->max_size = max_size;
        stackInstance->current_size = 0;

        // clear the buffer
        for (int i = 0; i < max_size; i++)
        {
            stackInstance->buffer[i] = '\0';
        }
        return stackInstance;
    }

    stackInstance->max_size = 0;
    stackInstance->current_size = 0;

    return stackInstance;
}


/*
* Function: deleteStack
* ---------------------
* Description: Frees the memory allocated for the stack and its buffer.
*
* Parameters:
*   stack_instance - Pointer to the stack to be deleted.
*
* Returns:
*   void
*/
void deleteStack(stack_t *stack_instance)
{

    if(stack_instance!= NULL){
        if(stack_instance->buffer != NULL){
            free(stack_instance->buffer);
        }
        free(stack_instance);
    }
    
}


/*
* Function: pushStack
* -------------------
* Description: Adds a new element to the top of the stack.
*              If the stack is full (i.e., at max capacity), the function logs an overflow message.
*
* Parameters:
*   stack_instance - Pointer to the stack where the data will be added.
*   data - The data to be pushed onto the stack.
*
* Returns:
*   The data pushed onto the stack, or ERROR if the stack is full.
*/
int pushStack(stack_t *stack_instance, int data)
{
    if (stack_instance->current_size == (stack_instance->max_size))
    {
        logPrint("Stack overflow !!!\n ");
        return ERROR;
    }
    stack_instance->buffer[stack_instance->current_size++] = data;

    return data;
}


/*
* Function: popStack
* ------------------
* Description: Removes the top element from the stack and returns it.
*              If the stack is empty, the function logs an empty stack message and returns ERROR.
*
* Parameters:
*   stack_instance - Pointer to the stack from which the data will be popped.
*   data - Pointer to store the popped data.
*
* Returns:
*   VALID if the operation is successful, ERROR if the stack is empty.
*/
error_code_t popStack(stack_t *stack_instance, int * data)
{

    if (stack_instance->current_size == 0)
    {
        logPrint("Stack empty !!!\n ");
        return ERROR;
    }

    *data = stack_instance->buffer[(stack_instance->current_size-1)];
    stack_instance->buffer[--stack_instance->current_size] = '\0';

    return VALID;
}

/*
* Function: printStack
* --------------------
* Description: Prints the contents of the stack, along with their indices.
*
* Parameters:
*   stack_instance - Pointer to the stack to be printed.
*
* Returns:
*   void
*/
void printStack(stack_t *stack_instance)
{
    printf("\n-----------\n");
    printf("Index | Data\n");
    for (int i = 0; i < stack_instance->max_size; i++)
    {
        printf("%02d   -> %02d\n", i, stack_instance->buffer[i]);
    }
    printf("-----------\n");
}


/*
    Function: topElement
    --------------------
    Description: Retrieves the top element of the stack without removing it.
            If the stack is empty, the function logs an empty stack message and returns ERROR.

    Parameters:
        tack_instance - Pointer to the stack.
        data - Pointer to store the top element.

    Returns:
        VALID if the stack is not empty, ERROR otherwise.
*/
error_code_t topElement(stack_t *stack_instance, int * data)
{
    if (stack_instance->current_size == 0)
    {
        logPrint("Stack empty !!!\n ");
        return ERROR;
    }
    *data = stack_instance->buffer[stack_instance->current_size];
    return VALID;
}



/*
    Function: notEmptyStack
    --------------------
    Description: Checks if the stack is not empty.
            If the stack is empty, it logs an empty stack message and returns ERROR.

    Parameters:
        stack_instance - Pointer to the stack to be checked.

    Returns:
        VALID if the stack is not empty, ERROR otherwise.
*/
error_code_t notEmptyStack(stack_t *stack_instance){
    if (stack_instance->current_size == 0)
    {
        logPrint("Stack empty !!!\n ");
        return ERROR;
    }
    return VALID;
}