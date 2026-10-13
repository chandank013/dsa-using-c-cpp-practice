
#include <iostream>
#include <cmath>
using namespace std;

// Node of the linked list
class Term {
public:
    int coeff;       // Coefficient of the term
    int exp;         // Exponent of the term
    Term* next;      // Pointer to the next node
};

// Polynomial class
class Polynomial {
private:
    Term* head;      // Pointer to the first node

public:
    // Default constructor
    Polynomial();

    // Parameterized constructor
    Polynomial(int coeff, int exp);

    // Create a polynomial
    void create();

    // Display a polynomial
    void display();

    // Add two polynomials
    void add(const Polynomial& p1, const Polynomial& p2);

    // Evaluate polynomial at a given value of x
    double evaluate(double x);

    // Destructor
    ~Polynomial();
};

// Default constructor
Polynomial::Polynomial() {
    head = nullptr;
}

// Parameterized constructor
// Creates a polynomial with one term: coeff * x^exp
Polynomial::Polynomial(int coeff, int exp) {
    head = new Term;

    head->coeff = coeff;
    head->exp = exp;
    head->next = nullptr;
}

// Create polynomial
void Polynomial::create() {
    int n, coeff, exp;
    Term* tail = nullptr;

    // Delete existing nodes, if any
    while (head != nullptr) {
        Term* temp = head;
        head = head->next;
        delete temp;
    }

    cout << "Enter the number of terms: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid number of terms!\n";
        return;
    }

    cout << "Enter coefficient and exponent "
         << "in descending order of exponents:\n";

    for (int i = 0; i < n; i++) {
        cin >> coeff >> exp;

        // Create a node without using a Term constructor
        Term* newNode = new Term;
        newNode->coeff = coeff;
        newNode->exp = exp;
        newNode->next = nullptr;

        // Attach the node to the linked list
        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
    }
}

// Display polynomial
void Polynomial::display() {
    Term* temp = head;
    bool first = true;

    if (head == nullptr) {
        cout << "0" << endl;
        return;
    }

    while (temp != nullptr) {
        // Print the sign
        if (!first) {
            if (temp->coeff > 0)
                cout << " + ";
            else if (temp->coeff < 0)
                cout << " - ";
        } else if (temp->coeff < 0) {
            cout << "-";
        }

        // Print the absolute coefficient
        int value = temp->coeff;

        if (value < 0)
            value = -value;

        cout << value << "x^" << temp->exp;

        first = false;
        temp = temp->next;
    }

    cout << endl;
}

// Add two polynomials into the current object
void Polynomial::add(const Polynomial& p1,
                     const Polynomial& p2) {
    // Clear the existing result list
    while (head != nullptr) {
        Term* temp = head;
        head = head->next;
        delete temp;
    }

    Term* a = p1.head;
    Term* b = p2.head;
    Term* tail = nullptr;

    // Add terms according to their exponents
    while (a != nullptr && b != nullptr) {
        int coeff, exp;

        if (a->exp > b->exp) {
            coeff = a->coeff;
            exp = a->exp;
            a = a->next;
        }
        else if (a->exp < b->exp) {
            coeff = b->coeff;
            exp = b->exp;
            b = b->next;
        }
        else {
            coeff = a->coeff + b->coeff;
            exp = a->exp;

            a = a->next;
            b = b->next;
        }

        // Skip terms whose coefficient is zero
        if (coeff != 0) {
            Term* newNode = new Term;
            newNode->coeff = coeff;
            newNode->exp = exp;
            newNode->next = nullptr;

            if (head == nullptr) {
                head = newNode;
            } else {
                tail->next = newNode;
            }

            tail = newNode;
        }
    }

    // Copy the remaining terms of the first polynomial
    while (a != nullptr) {
        Term* newNode = new Term;
        newNode->coeff = a->coeff;
        newNode->exp = a->exp;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
        a = a->next;
    }

    // Copy the remaining terms of the second polynomial
    while (b != nullptr) {
        Term* newNode = new Term;
        newNode->coeff = b->coeff;
        newNode->exp = b->exp;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
        b = b->next;
    }
}

// Evaluate polynomial at a given value of x
double Polynomial::evaluate(double x) {
    double result = 0;
    Term* temp = head;

    // Calculate coeff * x^exp for every term
    while (temp != nullptr) {
        result += temp->coeff * pow(x, temp->exp);
        temp = temp->next;
    }

    return result;
}

// Destructor
Polynomial::~Polynomial() {
    // Delete all nodes to free memory
    while (head != nullptr) {
        Term* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function
int main() {
    Polynomial p1, p2, sum;

    // Create the first polynomial
    cout << "First Polynomial:\n";
    p1.create();

    // Create the second polynomial
    cout << "\nSecond Polynomial:\n";
    p2.create();

    // Display both polynomials
    cout << "\nFirst Polynomial: ";
    p1.display();

    cout << "Second Polynomial: ";
    p2.display();

    // Add both polynomials
    sum.add(p1, p2);

    cout << "Sum of Polynomials: ";
    sum.display();

    // Evaluate polynomials
    double x;

    cout << "\nEnter the value of x: ";
    cin >> x;

    cout << "First polynomial at x = " << x
         << " is " << p1.evaluate(x) << endl;

    cout << "Second polynomial at x = " << x
         << " is " << p2.evaluate(x) << endl;

    cout << "Sum polynomial at x = " << x
         << " is " << sum.evaluate(x) << endl;

    return 0;
}
