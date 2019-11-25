#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;
typedef struct{
    ElemType *elem;
    int length;
    int listsize; //象征性的写一下
} List;

int InitList(List *L);
void DestoryList(List *L);
int ListEmpty(List L);
int ListLength(List L);
void GetElem(List L, int i, ElemType *e);
int LocateElem(List L, ElemType e, int (*compare)(const ElemType, const ElemType));
void PriorElem(List L, ElemType cur_e, ElemType *pre_e);
void NextElem(List L, ElemType cur_e, ElemType *next_e);
void ListInsert(List *L, int i, ElemType e);
void ListDelete(List *L, int i, ElemType *e);
