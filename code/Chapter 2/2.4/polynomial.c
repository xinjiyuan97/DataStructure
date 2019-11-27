#include "polynomial.h"

void CreatePolyn(Polynomial *P, int m) {
    float coef;
    int expn;
    Polynomial *p, *tmp;
    printf("Hello.");
    for (int i = 0; i < m; i++) {
        // scanf("%f %d", &coef, &expn);
        printf("Hello.");
        p = P;
        printf("Hello!");
        coef = 1.1;
        expn = 2;
        printf("Hello.");
        while (p -> next && p -> next -> val.expn <= expn) 
            p = p -> next;
        
        if (p -> next -> val.expn == expn)
            p -> next -> val.coef += coef;
        else {
            tmp = (Polynomial*) malloc(sizeof(Polynomial));
            printf("Hello ");
            tmp -> next = p -> next;
            tmp -> val.expn = expn;
            tmp -> val.coef = coef;
            p -> next = tmp;
        }
    }

    return;
}
void DestoryPolyn(Polynomial *P);
void PrintPolyn(Polynomial P) {
    Polynomial *p = P.next;
    while (p) {
        printf("(%.2f, %d) ->", p -> val.coef, p -> val.expn);
        p = p -> next;
    }
}
int PolynLength(Polynomial P);
void AddPolyn(Polynomial *Pa, Polynomial *Pb);
void SubtractPolyn(Polynomial *Pa, Polynomial *Pb);
void MultiplyPolyn(Polynomial *Pa, Polynomial *Pb);

int main() {
    Polynomial P;
    CreatePolyn(&P, 3);
    PrintPolyn(P);
    return 0;
}