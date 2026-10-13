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

    // Function to add two polynomials
    Polynomial operator+(Polynomial &p);
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

// Function to add two polynomials
Polynomial Polynomial::operator+(Polynomial &p) {
    Polynomial sum(num + p.num); // Maximum possible terms in the sum
    int i = 0, j = 0, k = 0;

    while (i < num && j < p.num) {
        if (terms[i].exp > p.terms[j].exp) {
            sum.terms[k++] = terms[i++];
        } else if (terms[i].exp < p.terms[j].exp) {
            sum.terms[k++] = p.terms[j++];
        } else {
            sum.terms[k] = terms[i];
            sum.terms[k++].coeff += p.terms[j++].coeff;
            i++;
        }
    }

    while (i < num) {
        sum.terms[k++] = terms[i++];
    }

    while (j < p.num) {
        sum.terms[k++] = p.terms[j++];
    }

    sum.num = k; // Update the number of terms in the sum
    return sum;
}




int main() {

    int n1, n2;
    cout << "Enter the number of terms in the first polynomial: ";
    cin >> n1;
    Polynomial p1(n1);
    cin >> p1;
    cout << "First Polynomial: " << p1;

    cout << "Enter the number of terms in the second polynomial: ";
    cin >> n2;
    Polynomial p2(n2);
    cin >> p2;
    cout << "Second Polynomial: " << p2;

    Polynomial sum = p1 + p2;
    cout << "Sum of Polynomials: " << sum;

    return 0;
}