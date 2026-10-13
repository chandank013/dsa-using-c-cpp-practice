
#include <iostream>
using namespace std;

class Element {
public:
    int i;              // Row index
    int j;              // Column index
    int x;              // Non-zero value
    Element* next;      // Pointer to next node

    Element(int row, int col, int value) {
        i = row;
        j = col;
        x = value;
        next = nullptr;
    }
};

class Sparse {
private:
    Element* head;

    // Insert a non-zero element at the end
    void insert(int i, int j, int x) {
        if (x == 0)
            return;

        Element* newNode = new Element(i, j, x);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Element* temp = head;

        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

public:
    int m, n;

    // Default constructor
    Sparse() {
        m = n = 0;
        head = nullptr;
    }

    // Parameterized constructor
    Sparse(int rows, int cols) {
        m = rows;
        n = cols;
        head = nullptr;
    }

    // Input sparse matrix
    void create(int num) {
        int i, j, x;

        cout << "Enter row, column and value "
             << "(0-based indices):\n";

        for (int k = 0; k < num; k++) {
            cin >> i >> j >> x;

            if (i < 0 || i >= m ||
                j < 0 || j >= n) {
                cout << "Invalid position. Try again:\n";
                k--;
                continue;
            }

            insert(i, j, x);
        }
    }

    // Display the complete matrix
    void display() const {
        Element* temp = head;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (temp != nullptr &&
                    temp->i == i && temp->j == j) {
                    cout << temp->x << " ";
                    temp = temp->next;
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    // Add two sparse matrices
    Sparse add(const Sparse& s) const {
        if (m != s.m || n != s.n) {
            cout << "Matrix dimensions do not match!\n";
            return Sparse();
        }

        Sparse sum(m, n);

        Element* p = head;
        Element* q = s.head;

        while (p != nullptr && q != nullptr) {
            if (p->i < q->i ||
                (p->i == q->i && p->j < q->j)) {

                sum.insert(p->i, p->j, p->x);
                p = p->next;
            }
            else if (q->i < p->i ||
                     (q->i == p->i && q->j < p->j)) {

                sum.insert(q->i, q->j, q->x);
                q = q->next;
            }
            else {
                sum.insert(p->i, p->j, p->x + q->x);

                p = p->next;
                q = q->next;
            }
        }

        while (p != nullptr) {
            sum.insert(p->i, p->j, p->x);
            p = p->next;
        }

        while (q != nullptr) {
            sum.insert(q->i, q->j, q->x);
            q = q->next;
        }

        return sum;
    }

    // Destructor
    ~Sparse() {
        while (head != nullptr) {
            Element* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Deep copy constructor
    Sparse(const Sparse& s) {
        m = s.m;
        n = s.n;
        head = nullptr;

        Element* temp = s.head;

        while (temp != nullptr) {
            insert(temp->i, temp->j, temp->x);
            temp = temp->next;
        }
    }

    // Copy assignment operator
    Sparse& operator=(const Sparse& s) {
        if (this == &s)
            return *this;

        while (head != nullptr) {
            Element* temp = head;
            head = head->next;
            delete temp;
        }

        m = s.m;
        n = s.n;

        Element* temp = s.head;

        while (temp != nullptr) {
            insert(temp->i, temp->j, temp->x);
            temp = temp->next;
        }

        return *this;
    }
};

int main() {
    int m, n, num1, num2;

    cout << "Enter dimensions (rows and columns): ";
    cin >> m >> n;

    if (m <= 0 || n <= 0) {
        cout << "Invalid dimensions!\n";
        return 1;
    }

    cout << "Enter number of non-zero elements in first matrix: ";
    cin >> num1;

    if (num1 < 0 || num1 > m * n) {
        cout << "Invalid number of elements!\n";
        return 1;
    }

    Sparse s1(m, n);
    s1.create(num1);

    cout << "Enter number of non-zero elements in second matrix: ";
    cin >> num2;

    if (num2 < 0 || num2 > m * n) {
        cout << "Invalid number of elements!\n";
        return 1;
    }

    Sparse s2(m, n);
    s2.create(num2);

    cout << "\nFirst Sparse Matrix:\n";
    s1.display();

    cout << "\nSecond Sparse Matrix:\n";
    s2.display();

    Sparse sum = s1.add(s2);

    cout << "\nSum of Sparse Matrices:\n";
    sum.display();

    return 0;
}
