#include <stdlib.h>
#include <stdio.h>


typedef struct {
    float coef;
    int expn;
} ElemType;

typedef struct LNode {
    ElemType val;
    struct LNode *next;
} Polynomial;

void CreatePolyn(Polynomial *P, int m);
void DestoryPolyn(Polynomial *P);
void PrintPolyn(Polynomial P);
int PolynLength(Polynomial P);
void AddPolyn(Polynomial *Pa, Polynomial *Pb);
void SubtractPolyn(Polynomial *Pa, Polynomial *Pb);
void MultiplyPolyn(Polynomial *Pa, Polynomial *Pb);
