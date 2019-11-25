#include "list.h"
#include <stdio.h>
int Equal(const ElemType a, const ElemType b) {
    return a == b;
}

int InitList(List *L) {
    L -> elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L -> elem)
        return -1;
    L -> length = 0;
    L -> listsize = LIST_INIT_SIZE;
    return 0;
}

void DestoryList(List *L) {
    if (!L -> elem)
        return;
    free(L -> elem);
}

int ListEmpty(List L) {
    if (L.length)
        return 0;
    return 1;
}

int ListLength(List L) {
    return L.length;
}

void GetElem(List L, int i, ElemType *e) {
    // O(1)
    if (i < L.length)
        *e = L.elem[i];
    else 
        *e = -1;
    return;
}

int LocateElem(List L, ElemType e, int (*compare)(const ElemType, const ElemType)) {
    // O(n)
    int len = ListLength(L);
    ElemType tmp;
    for (int i = 0; i < len; i++) {
        GetElem(L, i, &tmp);
        if (compare(tmp, e))
            return i;
    }
    return -1;
}

void PriorElem(List L, ElemType cur_e, ElemType *pre_e) {
    int index = LocateElem(L, cur_e, &Equal);
    if (index == -1 || index == 0)
        pre_e = 0;
    pre_e = &L.elem[index - 1];
}

void NextElem(List L, ElemType cur_e, ElemType *next_e) {
    int index = LocateElem(L, cur_e, &Equal);
    if (index == -1 || index == ListLength(L) - 1)
        next_e = 0;
    next_e = &L.elem[index + 1];
}

void ListInsert(List *L, int index, ElemType e) {
    ElemType *new;
    if (index < 0 || index > L -> length)
        return;
    if (L -> length >= L -> listsize - 1) {
        new = (ElemType *)realloc(L -> elem, (L -> listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!new)
            return;
        L -> elem = new;
        L -> listsize += LISTINCREMENT;
    }
    for (int i = L -> length - 1; i >= index; i--)
        L -> elem[i + 1] = L -> elem[i];
    L -> elem[index] = e;
    L -> length++;
}

void ListDelete(List *L, int index, ElemType *e) {
    if (index < 0 || index >= L -> length)
        return;
    *e = L -> elem[index];
    for (int i = index; i < L -> length; i++)
        L -> elem[i] = L -> elem[i - 1];
    L -> length--;
}

int main() {
    List l;
    InitList(&l);
    ListInsert(&l, 0, 1);
    ListInsert(&l, 0, 2);
    ElemType tmp;
    GetElem(l, 1, &tmp);
    printf("%d", tmp);
    DestoryList(&l);
}