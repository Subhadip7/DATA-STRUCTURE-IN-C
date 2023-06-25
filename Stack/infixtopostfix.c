#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 6
typedef struct {
    char data [MAX];
    int top;
} STACK;
void init (STACK *);
int push (STACK * , char);
int pop (STACK * , char *);
int isOperand(char);
int isLH(char, char);
int getv(char);
void infixToPostfix(char*, char*);


/* operand comes then it will go to output
   operator comes , 1. stack is empty -> push into stack
                    2. stack top contains '(' -> push into stack until ')' come then it will pop
                    3. stack top contains operator -> SS -> 1st S will go output
                                                    -> LH -> stay together into stack
                                                    -> HL -> H will go to output
                                                    */

 void init (STACK *s)
 {
    s->top = -1;
 }


int push (STACK *s , char val )
{
    if (s->top == MAX-1)
    {
        printf("Overflow \n");
        return 1;
    }
    s->top ++;
    s->data[s->top]= val;
    return 0;
}

int pop (STACK *s , char *val)
{
 if (s->top == -1)
  {
    printf("Under-flow\n");
    return 1;
  }
  *val = s->data[s->top];
  s->top --;
  return 0;
}

int isOperand(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int isLH(char op1, char op2) {
    if (getv(op1)< getv(op2))
    return 1;
    else 
    return 0;
}

int getv (char d)
{
    int k;
    switch (d)
    {
        case '+': k=1;break;
        case '-': k=1;break;
        case '*': k=2;break;
        case '/': k=2;break;
    }
  return k;
}

void infixToPostfix(char *inf, char *outf)
{
    STACK s1;
    init(&s1);
    int i = 0, j = 0;
    char p;
    while (inf[i] != '\0')
    {
        // operand comes then it will go to output
        if (isOperand(inf[i]))
        {
            outf[j++] = inf[i];
        }
        // if '(' comes then push
        else if (inf[i] == '(')
        {
            push(&s1, inf[i]);
        }
        // if ')' comes then pop until it reaches ')', then move to output
        else if (inf[i] == ')')
        {
            while (1) // this is an infinite loop
            {
                pop(&s1, &p);
                if (p == '(')
                    break;
                outf[j++] = p;
            }
        }
        else
        // for operator
        {
            if (s1.top == -1)
            {
                push(&s1, inf[i]);
            }
            else
            {
                pop(&s1, &p);
                if (p == '(')
                {
                    push(&s1, '(');
                    push(&s1, inf[i]);
                }
                else
                {
                    if (isLH(p, inf[i]))
                    {
                        push(&s1, p);
                        push(&s1, inf[i]);
                    }
                    else
                    {
                        outf[j++] = p;
                        i--;
                        // so that it comes to the previous character after i++ also
                    }
                }
            }
        }
        i++; // end of while loop
    }
    while (pop(&s1, &p) == 0)
    {
        outf[j++] = p;
    }
    outf[j] = '\0';
}




int main()
{
    char output [100];
    char infix[]= "A+B-(D*k+p)/R";
    infixToPostfix(infix, output);
    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", output);
    return 0;
}