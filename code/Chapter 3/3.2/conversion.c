#include <stdio.h>
#include "continueStack.h"

void conversion() {
    Stack s;
    int n;
    initStack(&s);
    scanf("%d", &n);
    while (n) {
        int tmp = n % 8;
        push(&s, &tmp);
        n /= 8;
    }
    while (!stackEmpty(s)) {
        int tmp;
        pop(&s, &tmp);
        printf("%d", tmp);
    }
    return;
}


int main() {
    conversion();
    return 0;
}