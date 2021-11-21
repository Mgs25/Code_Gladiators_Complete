/*----- FILE CALC.C --------------------------------------------------*/
/*                                                                    */
/* A simple calculator that does operations on integers that          */
/* are pushed and popped on a stack                                   */
/*--------------------------------------------------------------------*/

/************* NOTE *************/
/* Program tested on
/* Online GDB Debugger
/* CodeLite GNU GCC 9
/* Dev C++
/* Code::Blocks
/********************************/

/*-----------------------------------------------------------*/
/* OVERALL CHANGES IN THE PROJECT                            */
/* -> Fixed linker errors                                    */
/* -> Spacing in snippets to improve readability             */
/* -> Changed bracket style (personal preference)            */
/* -> Fixed illegal characters (⁄, –) (Not in character set) */
/*-----------------------------------------------------------*/

/*-----------------------------------------------------------*/
/* CHANGES MADE IN "CALC.c"                                  */
/* -> Added return type to non void returning main function  */
/* -> Change for(;;) to while(1) for readability             */
/* -> Added puts(buffer) to print the result to output stream*/
/*-----------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

IntStack stack = {0};

int main() {                                                // Added integer return type to main which is returning 0.
  Token tok;
  char word[100];
  char buf_out[100];
  int num, num2;
  
  while(1) {                                                // Changed (;;) to while(1) [preference]
    tok = read_token(word);
    
    switch(tok) {
      case T_STOP:
        break;
      case T_INTEGER:
        num = atoi(word);
        push(&stack, num);    
        break;
      case T_PLUS:
        push(&stack, pop(&stack) + pop(&stack));
        break;
      case T_MINUS:
        num = pop(&stack);
        push(&stack, num - pop(&stack));
        break;
      case T_TIMES:
        push(&stack, pop(&stack) * pop(&stack));
        break;
      case T_DIVIDE:
        num2 = pop(&stack);
        num = pop(&stack);
        push(&stack, num/num2);   
        break;
      case T_EQUALS:
        num = pop(&stack);
        sprintf(buf_out, "= %d ",num);
        puts(buf_out);                                      // Added the missing puts(buf_out) to print the result (element on top)
        push(&stack, num);
    }
    
    if (tok == T_STOP)
      break;
  }
  return 0;
}
