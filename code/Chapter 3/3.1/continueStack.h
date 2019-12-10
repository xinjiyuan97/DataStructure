#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int SElemType;
typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
} Stack;

void initStack(Stack *s);
void destoryStack(Stack *s);
void clearStack(Stack *s);
int stackEmpty(Stack s);
int stackLength(Stack s);
int getTop(Stack s, SElemType *e);
int push(Stack *s, SElemType *e);
int pop(Stack *s, SElemType *e);

