#include "list.h"

int Equal(const ElemType a, const ElemType b) {
    return a == b;
}

void UnionList(List *La, List Lb) {
    int la_len = ListLength(*La);
    int lb_len = ListLength(Lb);
    ElemType e;
    for (int i = 0; i < lb_len; i++) {
        GetElem(Lb, i, &e);
        if (!LocateElem(*La, e, Equal))
            ListInsert(La, ++la_len, e);
    }
    return;
}