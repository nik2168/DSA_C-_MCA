#include <iostream>
#include<stack>
using namespace std;

// okay here we need to sort a array using heap ... we can use any from min heap or max heap

// first -> make a max/min heap out of these random elemebts
// second -> as we know max heap has the greatest element at the root node
// now as we did in deleting node technique just swap the first with last and decerease the size of max heap
// repeat swaping again and again until we have only one element in the heap and guess what whole array is sorted wohhh ! you did it

// 18 jul 2023 .... just 2 days before the birthday

void maxheapify(int a[], int n)
{                  // here we will convert random set of element to a maxheap
    int s = n / 2; // every heap has n/2 starting position of the last lvl parent nodes
    while (s > 0)
    {
        int t = s;
        while (t <= n / 2)
        {
            int l = t * 2;
            int r = t * 2 + 1;
            int m = l;
            if (a[r] > a[l] && r <= n)
            {
                m = r;
            }
            if (a[m] > a[t])
            {
                swap(a[m], a[t]);
            }
            t++;
        }
        s--;
    }
}

void helper(int a[], int &s)
{ // here array is a max heap
    while (s != 1)
    {
        swap(a[1], a[s]);
        s--;
        int c = 1;
        while (c * 2 <= s)
        {
            int l = 2 * c;
            int r = 2 * c + 1;
            int m = l;
            if (r <= s && a[r] > a[l])
                m = r;
            if (a[m] > a[c])
            {
                swap(a[m], a[c]);
            }
            c = m;
        }
    }
}

int main()
{
    int a[] = {40, 10, 60, 5, 70, 8};
    int n = 5;

    maxheapify(a, n); // this will make a max heap out of it

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    int s = n;
    helper(a, s); // and this will sort all the element by swaping the root node with last element or by using deleting node technique

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}