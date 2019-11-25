
typedef int ElemType;
typedef struct{
    int val; //象征性的写一下
} List;

int InitList(List *L);
void DestoryList(List *L);
int ListEmpty(List L);
int ListLength(List L);
void GetElem(List L, int i, ElemType *e);
int LocateElem(List L, ElemType e, int (*compare)());
void PriorElem(List L, ElemType cur_e, ElemType *pre_e);
void NextElem(List L, ElemType cur_e, ElemType *next_e);
void ListInsert(List *L, int i, ElemType e);
void ListDelete(List *L, int i, ElemType *e);
