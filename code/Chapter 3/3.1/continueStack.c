#include "continueStack.h"
#include <stdio.h>
void initStack(Stack *s) {
    s -> base = (SElemType*) malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!s -> base)
        return;
    s -> top = s -> base;
    s -> stacksize = STACK_INIT_SIZE;
    return;
}

void destoryStack(Stack *s) {
    if (!s -> base)
        return;
    free(s -> base);
}

void clearStack(Stack *s) {
    s -> top = s -> base;
}

int stackEmpty(Stack s) {
    if (s.base == s.top)
        return 1;
    return 0;
}

int stackLength(Stack s) {
    return s.top - s.base;
}

int getTop(Stack s, SElemType *e) {
    if (s.top == s.base)
        return -1;
    *e = *(s.top - 1);
    return 0;
}

int push(Stack *s, SElemType *e) {
    if (s -> top - s -> base >= s -> stacksize) {
        s -> base = (SElemType *) realloc(s -> base, (s -> stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!s -> base)
            return -1;
        s -> top = s -> base + s -> stacksize;
        s -> stacksize += STACKINCREMENT;
    }
    *(s -> top ++) = *e;
    return 0;
}

int pop(Stack *s, SElemType *e) {
    if (s -> top == s -> base)
        return -1;
    *e = *(--s -> top);
    return 0;
}


int main() {
    Stack s;
    initStack(&s);
    int tmp = 4; 
    push(&s, &tmp);
    printf("%d\n", stackLength(s));
    tmp = 5;
    pop(&s, &tmp);
    printf("%d", tmp);
    return 0;
}
