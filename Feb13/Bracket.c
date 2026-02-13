#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}
char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int areBracketsBalanced(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }
        
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1)
                return 0;

            char popped = pop();
            if (!isMatchingPair(popped, exp[i]))
                return 0;
        }
    }

    return (top == -1);
}

int main() {
    char expression[MAX];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (areBracketsBalanced(expression))
        printf("Brackets are Balanced\n");
    else
        printf("Brackets are NOT Balanced\n");

    return 0;
}
