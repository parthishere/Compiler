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

void remove_spaces(char* s) {
    char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
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
 
    if(checkParenthesis(*expression) == ERROR){
        return;
    }
    
    remove_spaces(expression);

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
            printStack(stack);
            
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

    postFixExpr[postFixExprIndex] = '\0';
    deleteStack(stack);
} 



void parsePostfix(char * expression){
    stack_t * stack = createStack(50);
    
    while(*expression != '\0'){
        while(isOperand(*expression)){
           
        }
    }
    deleteStack(stack);
}