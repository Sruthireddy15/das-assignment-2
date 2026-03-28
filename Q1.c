#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int main() {
    char str[100];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    // Push all characters into stack
    for(i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    // Pop to reverse string
    printf("Reversed string: ");
    while(top != -1) {
        printf("%c", pop());
    }

    return 0;
}