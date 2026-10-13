
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

// Node of linked list
struct Term {
    int coeff;
    int exp;
    struct Term* next;
}*ply = nullptr;


void create() {
    struct Term *t, *last;
    int n, coeff, exp;

    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Enter coefficient and exponent in descending order of exponents:\n");
    for (int i = 0; i < n; i++) {
        t = (struct Term*)malloc(sizeof(struct Term));
        scanf("%d %d", &t->coeff, &t->exp);
        t->next = nullptr;

        if (ply == nullptr) {
            ply = last = t;
        } else {
            last->next = t;
            last = t;
        }
    }
}

void display(struct Term* p) {
    while (p != nullptr) {
        printf("%dx^%d", p->coeff, p->exp);
        if (p->next != nullptr) {
            printf(" + ");
        }
        p = p->next;
    }
    printf("\n");
}

void evaluate(struct Term* p, int x) {
    double result = 0;
    while (p != nullptr) {
        result += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    printf("Polynomial evaluated at x = %d: %.2f\n", x, result);
}

void add(struct Term* p1, struct Term* p2) {
    struct Term *p3 = nullptr, *last = nullptr;
    while (p1 != nullptr && p2 != nullptr) {
        struct Term* t = (struct Term*)malloc(sizeof(struct Term));
        if (p1->exp > p2->exp) {
            t->coeff = p1->coeff;
            t->exp = p1->exp;
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            t->coeff = p2->coeff;
            t->exp = p2->exp;
            p2 = p2->next;
        } else {
            t->coeff = p1->coeff + p2->coeff;
            t->exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }
        t->next = nullptr;

        if (p3 == nullptr) {
            p3 = last = t;
        } else {
            last->next = t;
            last = t;
        }
    }

    while (p1 != nullptr) {
        struct Term* t = (struct Term*)malloc(sizeof(struct Term));
        t->coeff = p1->coeff;
        t->exp = p1->exp;
        t->next = nullptr;

        if (p3 == nullptr) {
            p3 = last = t;
        } else {
            last->next = t;
            last = t;
        }
        p1 = p1->next;
    }

    while (p2 != nullptr) {
        struct Term* t = (struct Term*)malloc(sizeof(struct Term));
        t->coeff = p2->coeff;
        t->exp = p2->exp;
        t->next = nullptr;

        if (p3 == nullptr) {
            p3 = last = t;
        } else {
            last->next = t;
            last = t;
        }
        p2 = p2->next;
    }

    printf("Resultant polynomial after addition:\n");
    display(p3);
}

void freePolynomial(struct Term* p) {
    while (p != nullptr) {
        struct Term* temp = p;
        p = p->next;
        free(temp);
    }
}

// Main function
int main() {
    struct Term *p1 = nullptr, *p2 = nullptr;

    printf("Create first polynomial:\n");
    create();
    p1 = ply;
    printf("First polynomial: ");
    display(p1);

    printf("\nCreate second polynomial:\n");
    create();
    p2 = ply;
    printf("Second polynomial: ");
    display(p2);

    add(p1, p2);

    int x;
    printf("\nEnter a value for x to evaluate the first polynomial: ");
    scanf("%d", &x);
    evaluate(p1, x);

    printf("Enter a value for x to evaluate the second polynomial: ");
    scanf("%d", &x);
    evaluate(p2, x);
    
    return 0;
}