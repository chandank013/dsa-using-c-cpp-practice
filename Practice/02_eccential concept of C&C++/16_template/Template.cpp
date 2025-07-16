#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Template class for arithmetic operations
template <class T>
class Arithmatic
{
    private:
        int a, b;
    public:
        Arithmatic(T x, T y);
        T add(T x, T y);
        T sub(T x, T y);
        T mul(T x, T y);
        T div(T x, T y);
        // destructor
        ~Arithmatic();
};

template <class T>
Arithmatic<T>::Arithmatic(T x, T y)
{
    a = x;
    b = y;
}

template <class T>
T Arithmatic<T>::add(T x, T y)
{
    return x + y;
}

template <class T>
T Arithmatic<T>::sub(T x, T y)
{
    return x - y;
}

template <class T>
T Arithmatic<T>::mul(T x, T y)
{
    return x * y;
}

template <class T>
T Arithmatic<T>::div(T x, T y)
{
    if (y == 0) {
        std::cerr << "Division by zero error!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return x / y;
}

template <class T>
Arithmatic<T>::~Arithmatic()
{
    cout << "Destructor called for Arithmatic class" << endl;
}


int main()
{
    Arithmatic<int> arith(10, 5);
    Arithmatic<float> arithFloat(10.5, 5.5);
    Arithmatic<char> arithChar('A', 'B'); 
    
    cout << "Addition: " << arith.add(10, 5) << endl;
    cout << "Subtraction: " << arith.sub(10, 5) << endl;
    cout << "Multiplication: " << arith.mul(10, 5) << endl;
    cout << "Division: " << arith.div(10, 5) << endl;

    cout << "Addition (float): " << arithFloat.add(10.5, 5.5) << endl;
    cout << "Subtraction (float): " << arithFloat.sub(10.5, 5.5) << endl;
    cout << "Multiplication (float): " << arithFloat.mul(10.5, 5.5) << endl;
    cout << "Division (float): " << arithFloat.div(10.5, 5.5) << endl;

    cout << "Addition (char): " << arithChar.add('A', 'B') << endl;
    
  

    // Destructor will be called automatically when objects go out of scope
    cout << "End of main function" << endl;
    // Explicitly calling destructor for demonstration purposes


    return 0;
    
}