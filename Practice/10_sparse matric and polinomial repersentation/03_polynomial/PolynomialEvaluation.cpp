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

    // Function for evaluating the polynomial at a given value of x
    int evaluate(int x);
};

// Function to create a polynomial
istream& operator>>(istream &is, Polynomial &p) {
    cout << "Enter the terms (coefficient and exponent):" << endl;
    for (int i = 0; i < p.num; i++) {
        is >> p.terms[i].coeff >> p.terms[i].exp;
    }
    return is;
}

// Function to display the polynomial
ostream& operator<<(ostream &os, Polynomial &p) {
    for (int i = 0; i < p.num; i++) {
        os << p.terms[i].coeff << "x^" << p.terms[i].exp;
        if (i < p.num - 1) {
            os << " + ";
        }
    }
    os << endl;
    return os;
}

// Function for evaluating the polynomial at a given value of x
int Polynomial::evaluate(int x) {
    int result = 0;
    for (int i = 0; i < num; i++) {
        result += terms[i].coeff * pow(x, terms[i].exp);
    }
    return result;
}


int main() {

    int n;
    cout << "Enter the number of terms in the polynomial: ";
    cin >> n;

    Polynomial p(n);
    cin >> p;

    // Display the polynomial
    cout << "The polynomial is: " << p;
    int x;
    cout << "Enter the value of x to evaluate the polynomial: ";
    cin >> x;
    cout << "The value of the polynomial at x = " << x << " is: " << p.evaluate(x) << endl;

    return 0;
}