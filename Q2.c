#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int main() {
    char exp[100];
    int i;

    printf("Enter expression: ");
    scanf("%s", exp);

    for(i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '(') {
            push('(');
        }
        else if(exp[i] == ')') {
            if(isEmpty()) {
                printf("Not Balanced");
                return 0;
            }
            pop();
        }
    }

    if(isEmpty())
        printf("Balanced Expression");
    else
        printf("Not Balanced");

    return 0;
}