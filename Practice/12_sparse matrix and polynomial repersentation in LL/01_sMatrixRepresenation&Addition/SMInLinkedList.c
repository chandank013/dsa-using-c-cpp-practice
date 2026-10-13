
#include <stdio.h>
#include <stdlib.h>

struct Element {
    int i;                  // Row index
    int j;                  // Column index
    int x;                  // Non-zero value
    struct Element* next;   // Pointer to next node
};

struct Sparse {
    int m, n;               // Rows and columns
    struct Element* head;   // Head of linked list
};

// Create a new node
struct Element* createNode(int i, int j, int x) {
    struct Element* newNode =
        (struct Element*)malloc(sizeof(struct Element));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->i = i;
    newNode->j = j;
    newNode->x = x;
    newNode->next = NULL;

    return newNode;
}

// Initialize sparse matrix
void initialize(struct Sparse* s, int m, int n) {
    s->m = m;
    s->n = n;
    s->head = NULL;
}

// Insert node at the end
void insert(struct Sparse* s, int i, int j, int x) {
    if (x == 0)
        return;

    struct Element* newNode = createNode(i, j, x);

    if (s->head == NULL) {
        s->head = newNode;
        return;
    }

    struct Element* temp = s->head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Create sparse matrix
void create(struct Sparse* s, int num) {
    int i, j, x;

    printf("Enter row, column and value (0-based indices):\n");

    for (int k = 0; k < num; k++) {
        scanf("%d %d %d", &i, &j, &x);

        if (i < 0 || i >= s->m ||
            j < 0 || j >= s->n) {
            printf("Invalid position! Try this term again.\n");
            k--;
            continue;
        }

        insert(s, i, j, x);
    }
}

// Display sparse matrix in full matrix form
void display(struct Sparse* s) {
    struct Element* temp = s->head;

    for (int i = 0; i < s->m; i++) {
        for (int j = 0; j < s->n; j++) {
            if (temp != NULL &&
                temp->i == i && temp->j == j) {
                printf("%d ", temp->x);
                temp = temp->next;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Add two sparse matrices
struct Sparse add(struct Sparse* a, struct Sparse* b) {
    struct Sparse sum;
    initialize(&sum, a->m, a->n);

    if (a->m != b->m || a->n != b->n) {
        printf("Matrix dimensions do not match!\n");
        return sum;
    }

    struct Element* p = a->head;
    struct Element* q = b->head;

    while (p != NULL && q != NULL) {
        if (p->i < q->i ||
            (p->i == q->i && p->j < q->j)) {

            insert(&sum, p->i, p->j, p->x);
            p = p->next;
        }
        else if (q->i < p->i ||
                 (q->i == p->i && q->j < p->j)) {

            insert(&sum, q->i, q->j, q->x);
            q = q->next;
        }
        else {
            int value = p->x + q->x;

            insert(&sum, p->i, p->j, value);

            p = p->next;
            q = q->next;
        }
    }

    while (p != NULL) {
        insert(&sum, p->i, p->j, p->x);
        p = p->next;
    }

    while (q != NULL) {
        insert(&sum, q->i, q->j, q->x);
        q = q->next;
    }

    return sum;
}

// Free linked list memory
void freeSparse(struct Sparse* s) {
    struct Element* temp;

    while (s->head != NULL) {
        temp = s->head;
        s->head = s->head->next;
        free(temp);
    }
}

int main() {
    int m, n, num1, num2;

    struct Sparse s1, s2, sum;

    printf("Enter dimensions (rows and columns): ");
    scanf("%d %d", &m, &n);

    if (m <= 0 || n <= 0) {
        printf("Invalid matrix dimensions!\n");
        return 1;
    }

    printf("Enter number of non-zero elements in first matrix: ");
    scanf("%d", &num1);

    if (num1 < 0 || num1 > m * n) {
        printf("Invalid number of elements!\n");
        return 1;
    }

    initialize(&s1, m, n);
    create(&s1, num1);

    printf("Enter number of non-zero elements in second matrix: ");
    scanf("%d", &num2);

    if (num2 < 0 || num2 > m * n) {
        printf("Invalid number of elements!\n");
        freeSparse(&s1);
        return 1;
    }

    initialize(&s2, m, n);
    create(&s2, num2);

    printf("\nFirst Sparse Matrix:\n");
    display(&s1);

    printf("\nSecond Sparse Matrix:\n");
    display(&s2);

    sum = add(&s1, &s2);

    printf("\nSum of Sparse Matrices:\n");
    display(&sum);

    freeSparse(&s1);
    freeSparse(&s2);
    freeSparse(&sum);

    return 0;
}
