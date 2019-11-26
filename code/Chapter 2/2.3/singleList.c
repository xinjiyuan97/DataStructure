#include "singleList.h"

void CreateList(List *L, int n) {
    List *p;
    *L = *(List*) malloc(sizeof(struct LNode));
    L -> next = 0;
    while (n--) {
        p = (List*) malloc(sizeof(struct LNode));
        scanf("%d", &(p -> val));
        p -> next = L -> next;
        L -> next = p;
    }
}

void GetElem(List *L, int i, ElemType *e) {
    List *p = L -> next;
    while (p && i--) 
        p = p -> next;
    if (!p)
        return;
    *e = p -> val;
    return;
}

void ListInsert(List *L, int i, ElemType e) {
    List *p = L -> next, *tmp;
    while (p && i--) 
        p = p -> next;
    if (!p)
        return;
    tmp = (List*) malloc(sizeof(struct LNode));
    tmp -> next = p -> next;
    p -> next = tmp;
}

void ListDelete(List *L, int i, ElemType *e) {
    List *p = L -> next, *tmp;
    while (p && i--)
        p = p -> next;
    if (!p)
        return;
    tmp = p -> next;
    p -> next = p -> next -> next;
    free(tmp);
}

int main() {
    List * L;
    CreateList(L, 4);
    ElemType tmp;
    GetElem(L, 1, &tmp);
    printf("%d", tmp);
    return 0;
}