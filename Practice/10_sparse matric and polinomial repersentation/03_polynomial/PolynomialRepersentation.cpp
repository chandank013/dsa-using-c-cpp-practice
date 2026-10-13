#include <iostream>

using namespace std;

class Term {
public:
    int coeff; // Coefficient of the term
    int exp;   // Exponent of the term
};

class Polynomial {
public:
    int num;      // Number of terms in the polynomial
    Term *terms;  // Array of terms

    // Default constructor
    Polynomial() {
        num = 0;
        terms = nullptr;
    }

    // Parameterized constructor
    Polynomial(int n) {
        this->num = n;
        this->terms = new Term[n];
    }

    // Destructor to free allocated memory
    ~Polynomial() {
        delete[] terms;
    }

    // Function to create a polynomial
    friend istream& operator>>(istream &is, Polynomial &p);

    // Function to display the polynomial
    friend ostream& operator<<(ostream &os, Polynomial &p);
};

// Function to create a polynomial
istream& operator>>(istream &is, Polynomial &p) {
    cout << "Enter the terms (coefficient and exponent):" << endl;
    for (int i = 0; i < p.num; i++) {
        is >> p.terms[i].coeff >> p.terms[i].exp;
    }
    return is;
}


int main() {

    int n1, n2;
    cout << "Enter the number of terms in the first polynomial: ";
    cin >> n1;
    Polynomial p1(n1);
    cin >> p1;
    cout << "First Polynomial: " << p1;

    return 0;
}