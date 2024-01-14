#include "parenthesis.h"

#define CURLY_BRACES_OPEN  '{'
#define CURLY_BRACES_CLOSE '}'

#define SQUARE_BRACES_OPEN  '['
#define SQUARE_BRACES_CLOSE ']'

#define ROUND_BRACES_OPEN  '('
#define ROUND_BRACES_CLOSE ')'



error_code_t checkParenthesis(char * expr){
    char * temp = expr;

    int length_of_expression = 0;
    while(*temp != '\0'){
        length_of_expression++;
        temp++;
    }

    stack_t * stack_for_expression = createStack(length_of_expression);

    while(*expr != '\0'){
        if (*expr == '}' || *expr == ']' || *expr == ')'){
            int bracket;
            error_code_t error_type = popStack(stack_for_expression, &bracket);

            if (error_type == ERROR){
                printf("Started Braces with closed braces, Pair not found ! \n");
                deleteStack(stack_for_expression);
                return ERROR;
            }
;
            if (bracket != ((*expr)-2) && bracket != ((*expr)-1)){
                printf("Braces sequence is not correct !\n");
                deleteStack(stack_for_expression);
                return ERROR;
            }

        }
        else if (*expr == '{' || *expr == '[' || *expr == '('){
            pushStack(stack_for_expression, *expr);
            
        }
        
        expr++;
    }
    if(notEmptyStack(stack_for_expression) == ERROR) return VALID;
    
    deleteStack(stack_for_expression);
    return ERROR;

}