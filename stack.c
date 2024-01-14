#include "stack.h"


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

void deleteStack(stack_t *stack_instance)
{

    if(stack_instance!= NULL){
        if(stack_instance->buffer != NULL){
            free(stack_instance->buffer);
        }
        free(stack_instance);
    }
    
}

int pushStack(stack_t *stack_instance, int data)
{
    if (stack_instance->current_size == (stack_instance->max_size))
    {
        log("Stack overflow !!!\n ");
        return ERROR;
    }
    stack_instance->buffer[stack_instance->current_size++] = data;

    return data;
}

error_code_t popStack(stack_t *stack_instance, int * data)
{

    if (stack_instance->current_size == 0)
    {
        log("Stack empty !!!\n ");
        return ERROR;
    }

    *data = stack_instance->buffer[(stack_instance->current_size-1)];
    stack_instance->buffer[--stack_instance->current_size] = '\0';

    return VALID;
}

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

error_code_t topElement(stack_t *stack_instance, int * data)
{
    if (stack_instance->current_size == 0)
    {
        log("Stack empty !!!\n ");
        return ERROR;
    }
    *data = stack_instance->buffer[stack_instance->current_size];
    return VALID;
}

error_code_t notEmptyStack(stack_t *stack_instance){
    if (stack_instance->current_size == 0)
    {
        log("Stack empty !!!\n ");
        return ERROR;
    }
    return VALID;
}