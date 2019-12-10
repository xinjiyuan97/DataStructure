#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct DuLNode{
    ElemType val; 
    struct DuLNode *next;
    struct DuLNode *prior;
} List;


void CreateList(List *L, int n);
void DestoryList(List *L);
int ListEmpty(List L);
int ListLength(List L);
void GetElem(List *L, int i, ElemType *e);
int LocateElem(List L, ElemType e, int (*compare)(const ElemType, const ElemType));
void PriorElem(List L, ElemType cur_e, ElemType *pre_e);
void NextElem(List L, ElemType cur_e, ElemType *next_e);
void ListInsert(List *L, int i, ElemType e);
void ListDelete(List *L, int i, ElemType *e);
