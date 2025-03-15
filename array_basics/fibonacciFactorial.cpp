#include <iostream>
#include <vector>
using namespace std;

void printFibonacci(int n)
{
    cout << "Fibonacci Series upto " << n << " is : "<<endl;

    int a = 0, b = 1;

    cout << a << ", " << b << ", ";

    for (int i = 2; i < n; i++)
    {
        int t = a + b;
        a = b;
        b = t;
        cout << b << ", ";
    }

    cout << endl;
}

void printFactorial(int n)
{
    cout << "Factorial of n is : " << endl;

    int res = 1;

    cout<<res;

    for (int i = 2; i <= n; i++)
    {
        cout<< " * "<<i;
        res *= i;
    }
    cout << " = " << res;
    cout << endl;
}

void printRecursiveFibonacci(int a, int b, int i, int n){
    if(i >= n) {
        cout<<endl;
        return;
    }

    if(a == 0){
        cout<<a<<", "<<b<<", ";
    }
    cout<<b + a<<", ";
    printRecursiveFibonacci(b, a+b, i + 1, n);
}

void printRecursiveFactorial(int res, int n)
{
    if(n <= 1){
        cout<<n<<" = "<<res * n<<endl;
        return;
    }
   cout<<n<<" * ";
    printRecursiveFactorial(res * n, n - 1);

}

    int
    main()
{

    int n;
    cin >> n;

    printFibonacci(n);
    printFactorial(n);
    cout << "Recursive Fibonacci : " << endl;
    printRecursiveFibonacci(0, 1, 2, n);
    cout<<"Recursive Factorial : "<<endl;
    printRecursiveFactorial(1, n);

    return 0;
}

/*
6
Fibonacci Series upto 6 is :
0, 1, 1, 2, 3, 5,
Factorial of n is :
1 * 2 * 3 * 4 * 5 * 6 = 720
Recursive Fibonacci :
0, 1, 1, 2, 3, 5,
Recursive Factorial :
6 * 5 * 4 * 3 * 2 * 1 = 720
*/