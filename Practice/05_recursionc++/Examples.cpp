#include<iostream>

using namespace std;


// sum of first n natural numbers using recursion
int sumOfNaturals(int n) {
    if(n > 0) {
        return sumOfNaturals(n-1) + n;
    }
    return 0;
}

// factorial of a number using recursion
int factorial(int n) {
    if(n == 0) {
        return 1;
    }
    return factorial(n-1) * n;
}

// power of a number using recursion
int power(int x, int n) {
    if(n == 0) {
        return 1;
    }
    return x * power(x, n-1);
}

int power2(int x, int n) {
    if(n == 0) {
        return 1;
    }
    if(n % 2 == 0) {
        return power2(x*x, n/2);
    } else {
        return x * power2(x*x, n/2);
    }
}

// Taylor  series expansion of e^x using recursion
double taylorSeries(double x, int n) {
    static int p=1, f=1;  // to store the current power and factorial
    int r;
    if(n == 0) {
        return 1;
    }
    else {
        // return taylorSeries(x, n-1) + power(x, n) / factorial(n);
        
        r = taylorSeries(x, n-1);
        p = p * x;  // calculate the next power
        f = f * n;  // calculate the next factorial
        return r + p/f;  // add the term to the result
    }
}
  
// Taylor  series using Horner's method using loop
double taylorSeriesHorner(double x, int n) {
    double s = 1;  // e^0 = 1
    for(int i = n; i > 0; i--) {
        s = 1 + (x * s) / i;  // calculate the next term using Horner's method
    }
    return s;
}

// Taylor  series using Horner's method (optimized) using recursion
double taylorSeriesHornerRec(double x, int n) {
    static double s = 1;  // e^0 = 1
    if(n == 0) {
        return 1;  // e^0 = 1
    }
    else {
        s = 1 + (x * s) / n;  // calculate the next term using Horner's method
        return taylorSeriesHornerRec(x, n-1);  // recursive call for the next term
    }
}

// sine series expansion of sin(x) using recursion
double sineSeries(double x, int n) {
    static double s = x;  // sin(x) = x - x^3/3! + x^5/5! - ...
    if(n == 0) {
        return s;  // return the result when n reaches 0
    }
    s = s * (-1) * (x * x) / ((n+1) * (n+2));  // calculate the next term in the series
    return sineSeries(x, n-1);  // recursive call for the next term
}

// cosine series expansion of cos(x) using recursion
double cosineSeries(double x, int n) {
    static double s = 1;  // cos(x) = 1 - x^2/2! + x^4/4! - ...
    if(n == 0) {
        return s;  // return the result when n reaches 0
    }
    s = s * (-1) * (x * x) / ((n) * (n-1));  // calculate the next term in the series
    return cosineSeries(x, n-1);  // recursive call for the next term
}

// Fibonacci series using recursion
int fibonacci(int n) {
    if(n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

// Fibonacci series using loop
void fibonacciLoop(int n) {
    int a = 0, b = 1, c;
    cout << a << " " << b << " ";
    for(int i = 2; i < n; i++) {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    cout << endl;
}

// Fibonacci series using recursion (optimized using memoization)
int fibonacciMemo(int n, int memo[]) {
    if(n <= 1) {
        return n;
    }
    if(memo[n] != -1) {
        return memo[n];  // return the cached result if it exists
    }
    memo[n] = fibonacciMemo(n-1, memo) + fibonacciMemo(n-2, memo);  // calculate and cache the result
    return memo[n];
}


//1.0 nCr using recursion (optimized using Pascal's triangle)
int nCr(int n, int r) {
    if(r == 0 || r == n) {
        return 1;
    }
    return nCr(n-1, r-1) + nCr(n-1, r);
}

//2.0 nCr using recursion (optimized using factorial)
int nCr1(int n, int r) {
    if(r == 0 || r == n) {
        return 1;
    }
    int t1, t2, t3;
    t1 = factorial(n);
    t2 = factorial(r);
    t3 = factorial(n-r);
    return t1 / (t2 * t3);
}

// 3.0 nCr using loop
int nCr2(int n, int r) {
    if(r == 0 || r == n) {
        return 1;
    }
    int res = 1;
    for(int i = 1; i <= r; i++) {
        res = res * (n - r + i) / i;  // calculate the result using the formula nCr = n! / (r! * (n-r)!)
    }
    return res;
}

// 4.0 nCr using recursion (optimized using Pascal's triangle and memoization)
int nCr3(int n, int r, int memo[100][100]) {
    if(r == 0 || r == n) {
        return 1;
    }
    if(memo[n][r] != -1) {
        return memo[n][r];  // return the cached result if it exists
    }
    memo[n][r] = nCr3(n-1, r-1, memo) + nCr3(n-1, r, memo);  // calculate and cache the result
    return memo[n][r];
}

// Tower of Hanoi using recursion
void towerOfHanoi(int n, char from, char to, char aux) {
    if(n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    towerOfHanoi(n-1, from, aux, to);  // move n-1 disks from 'from' to 'aux'
    cout << "Move disk " << n << " from " << from << " to " << to << endl;  // move the nth disk from 'from' to 'to'
    towerOfHanoi(n-1, aux, to, from);  // move n-1 disks from 'aux' to 'to'
}

// GCD of two numbers using recursion
int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// LCM of two numbers using recursion
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n = 5;

    // sum of first n natural numbers using recursion
    cout << "Sum of first n natural numbers using recursion: " << endl;
    cout << sumOfNaturals(n) << endl;  // output: 15 (1+2+3+4+5)

    // factorial of a number using recursion
    cout << "Factorial of a number using recursion: " << endl;
    cout << factorial(n) << endl;  // output: 120 (5*4*3*2*1)

    // power of a number using recursion
    cout << "Power of a number using recursion: " << endl;
    cout << power(2, 3) << endl;  // output: 8 (2^3)
    cout << "Power of a number using recursion (optimized): " << endl;
    cout << power2(2, 3) << endl;  // output: 8 (2^3)

    // Taylor series expansion of e^x using recursion
    cout << "Taylor series expansion of e^x using recursion: " << endl;
    cout << taylorSeries(1, 10) << endl;  // output: approximately 2.71828

    // Taylor series expansion of e^x using Horner's method
    cout << "Taylor series expansion of e^x using Horner's method: " << endl;
    cout << taylorSeriesHorner(1, 10) << endl;  // output: approximately 2.71828
    // Taylor series expansion of e^x using Horner's method (optimized) using recursion
    cout << "Taylor series expansion of e^x using Horner's method (optimized) using recursion: " << endl;
    cout << taylorSeriesHornerRec(1, 10) << endl;  // output: approximately 2.71828

    // sine series expansion of sin(x) using recursion
    cout << "Sine series expansion of sin(x) using recursion: " << endl;
    cout << sineSeries(1, 10) << endl;  // output: approximately 0.84147
    // cosine series expansion of cos(x) using recursion
    cout << "Cosine series expansion of cos(x) using recursion: " << endl;
    cout << cosineSeries(1, 10) << endl;  // output: approximately 0.54030

    // Fibonacci series using recursion
    cout << "Fibonacci series using recursion: " << endl;
    for(int i = 0; i < 10; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
    // Fibonacci series using loop
    cout << "Fibonacci series using loop: " << endl;
    fibonacciLoop(10);  // output: 0 1 1 2 3 5 8 13 21 34

    // Fibonacci series using recursion (optimized using memoization)
    cout << "Fibonacci series using recursion (optimized using memoization): " << endl;
    int memo[10];
    for(int i = 0; i < 10; i++) {
        memo[i] = -1;  // initialize the memoization array with -1
    }
    // calculate and print the Fibonacci series using memoization
    for(int i = 0; i < 10; i++) {
        cout << fibonacciMemo(i, memo) << " ";
    }
    cout << endl;

    // nCr using recursion
    cout << "nCr using recursion: " << endl;
    cout << nCr(5, 2) << endl;  // output: 10
    // nCr using recursion (optimized using factorial)
    cout << "nCr using recursion (optimized using factorial): " << endl;
    cout << nCr1(5, 2) << endl;  // output: 10
    // nCr using loop
    cout << "nCr using loop: " << endl;
    cout << nCr2(5, 2) << endl;  // output: 10
    // nCr using recursion (optimized using Pascal's triangle and memoization)
    cout << "nCr using recursion (optimized using Pascal's triangle and memoization): " << endl;
    int memo2[100][100];
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            memo2[i][j] = -1;  // initialize the memoization array with -1
        }
    }
    cout << nCr3(5, 2, memo2) << endl;  // output: 10


    // GCD of two numbers using recursion
    cout << "GCD of two numbers using recursion: " << endl;
    cout << gcd(12, 8) << endl;  // output: 4

    // LCM of two numbers using recursion
    cout << "LCM of two numbers using recursion: " << endl;
    cout << lcm(12, 8) << endl;  // output: 24

    // Tower of Hanoi using recursion
    cout << "Tower of Hanoi using recursion: " << endl;
    towerOfHanoi(3, 'A', 'C', 'B');

    return 0;
}