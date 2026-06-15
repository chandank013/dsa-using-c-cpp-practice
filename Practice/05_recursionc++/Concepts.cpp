#include<iostream>

using namespace std;

// A recursive function is a function that calls itself in order to solve a problem.
void fun(int n) {
    if (n>0) {
        cout << n << " ";
        fun(n-1);
    }
}

// The above function prints the numbers from n down to 1.
void fun2(int n) {
    if (n>0) {
        fun2(n-1);
        cout << n << " ";
    }
}



int fun3(int n) {
    if(n > 0) {
        return fun3(n-1) + n;
    }
    return 0;
}


int fun4(int n) {
    static int count = 0;
    if(n > 0) {
        count++;
        return fun4(n-1) + count;
    }
    return 0;
}


int x = 0;
int fun5(int n) {
    if(n > 0) {
        x++;
        return fun5(n-1)+ x; 
    }
    return 0;
}  


// Type of Recursion:

// 1. Tail Recursion: A recursive function is said to be tail recursive if the recursive call is the last statement in the function.
void tailRecursion(int n) {
    if(n > 0) {
        cout << n << " ";
        tailRecursion(n-1);
    }
}

// 2. Head Recursion: A recursive function is said to be head recursive if the recursive call is the first statement in the function.
void headRecursion(int n) {
    if(n > 0) {
        headRecursion(n-1);
        cout << n << " ";
    }
}

// 3. Tree Recursion: A recursive function is said to be tree recursive if the function makes more than one call to itself.
void treeRecursion(int n) {
    if(n > 0) {
        cout << n << " ";
        treeRecursion(n-1);
        treeRecursion(n-1);
    }
}

// 4. Indirect Recursion: A recursive function is said to be indirect recursive if the function calls another function which in turn calls the  first function.
void indirectRecursionB(int n);
void indirectRecursionA(int n)
{
    if(n > 0) {
        cout << n << " ";
        indirectRecursionB(n-1);
    }
};
void indirectRecursionB(int n) {
    if(n > 0) {
        cout << n << " ";
        indirectRecursionA(n/2);
    }
}

// 5. Mutual Recursion: A recursive function is said to be mutual recursive if the function calls another function which in turn calls the first function.
void mutualRecursionA(int n);
void mutualRecursionB(int n);

void mutualRecursionA(int n)
{
    if(n > 0)
    {
        cout << "A: " << n << " ";
        mutualRecursionB(n - 1);
    }
}

void mutualRecursionB(int n)
{
    if(n > 0)
    {
        cout << "B: " << n << " ";
        mutualRecursionA(n - 1);
    }
}

// 6. Nested Recursion: A recursive function is said to be nested recursive if the function calls itself in a nested manner.
int nestedRecursion(int n) {
    if(n > 100) {
        return n-10;
    }
    else {
        return nestedRecursion(nestedRecursion(n+11));  
    }
}
    

// 7. Linear Recursion: A recursive function is said to be linear recursive if the function makes only one call to itself.
void linearRecursion(int n) {
    if(n > 0) {
        cout << n << " ";
        linearRecursion(n-1);
        cout << n << " ";
    }
}

// 8. Binary Recursion: A recursive function is said to be binary recursive if the function makes two calls to itself.
void binaryRecursion(int n) {
    if(n > 0) {
        cout << n << " ";
        binaryRecursion(n-1);
        binaryRecursion(n-1);
    }
}

// 9. Multiple Recursion: A recursive function is said to be multiple recursive if the function makes more than two calls to itself.
void multipleRecursion(int n) {
    if(n > 0) {
        cout << n << " ";
        multipleRecursion(n-1);
        multipleRecursion(n-1);
        multipleRecursion(n-1);
    }
}


// 10. Infinite Recursion: A recursive function is said to be infinite recursive if the function calls itself indefinitely without a base case.
void infiniteRecursion(int n) {
    cout << n << " ";
    infiniteRecursion(n+1);
}

// 11. Direct Recursion: A recursive function is said to be direct recursive if the function calls itself directly.
void directRecursion(int n) {
    if(n > 0) {
        cout << n << " ";
        directRecursion(n-1);
    }
}


int main() {
    int n = 5;

    cout << "Recursion: " << endl;
    fun(n);   // output: 5 4 3 2 1
    cout << endl;

    cout << "Recursion: " << endl;
    fun2(n);  // output: 1 2 3 4 5
    cout << endl;

    cout << "Recursion to sum: " << endl;
    cout << fun3(n) << endl;  // output: 15 (1+2+3+4+5)  
    
    cout << "Recursion to sum: " << endl;
    cout << fun4(n) << endl;  // output: 25 (1+2+3+4+5 + 1+2+3+4 + 1)
    cout << fun5(n) << endl;  // output: 25 (1+2+3+4+5 + 1+2+3+4 + 1) 

    // Types of Recursion:
    cout << "Tail Recursion: " << endl;
    tailRecursion(n);  // output: 5 4 3 2
    cout << endl;

    cout << "Head Recursion: " << endl;
    headRecursion(n);  // output: 1 2 3 4
    cout << endl;

    cout << "Tree Recursion: " << endl;
    treeRecursion(n);  // output: 5 4 4 3 3 3 2 2 2 2 1 1 1 1 1
    cout << endl;

    cout << "Indirect Recursion: " << endl;
    indirectRecursionA(n);  // output: 5 4 3 2 1
    cout << endl;

    cout << "Mutual Recursion: " << endl;
    mutualRecursionA(n);  // output: A: 5 B: 4 A: 3 B: 2 A: 1
    cout << endl;

    cout << "Linear Recursion: " << endl;
    linearRecursion(n);  // output: 5 4 3 2 1
    cout << endl;

    cout << "Binary Recursion: " << endl;
    binaryRecursion(n);  // output: 5 4 4 3 3 3 2 2 2 2 1 1 1 1 1
    cout << endl;

    cout << "Multiple Recursion: " << endl;
    multipleRecursion(n);  // output: 5 4 4 3 3 3 2 2 2 2 1 1 1 1 1
    cout << endl;
    

    cout << "direct Recursion: " << endl;
    directRecursion(n);  // output: 5 4 3 2 1
    cout << endl;

    cout << "nested Recursion: " << endl;
    int x= 95;
    cout << nestedRecursion(x) << endl;  // output: 5 4 3 2 1


    return 0;
}