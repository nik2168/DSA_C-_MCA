// 1,2,3. Write  a program in C++ to insert, delete & average the element in between the array;

#include <iostream>
using namespace std;

void insertInBetween(int arr[], int ele, int p, int &size)
{

    if (p < 0 || p > size)
    {
        cout << "Position not valid !";
        return;
    }

    int pre;

    cout << "Array after inserting ele " << ele << " at position " << p << " is :" << endl;

    for (int i = 0; i < size + 1; i++)
    {
        if (i == p)
        {
            pre = arr[i];
            arr[i] = ele;
        }
        if (i > p)
        {
            int cur = arr[i];
            arr[i] = pre;
            pre = cur;
        }
        cout << arr[i] << " ";
    }
    size++;
    cout<<endl;
}

void deleteTheElement(int arr[], int p, int &size)
{
    if (p < 0 || p > size)
    {
        cout << "Position not valid !";
        return;
    }
    int pre;

    cout << "Array after deleting at position " << p << " is :" << endl;

    for (int i = 0; i < size - 1; i++)
    {
        if (i >= p)
        {
           arr[i] = arr[i + 1];
        }
        cout<<arr[i]<<" ";
    }
    size--;
    cout<<endl;
}

int main()
{

    int size;
    cin >> size;

    int arr[size];

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        int val;
        cin >> val;
        arr[i] = val;
        sum += arr[i];
    }

    cout<<"The average of array is : "<<sum/size<<endl;

    cout<<"Insert Operation ->"<<endl;
    int ele, p;
    cout << "Element : ";
    cin >> ele;

    cout << "Position : ";
    cin >> p;

    insertInBetween(arr, ele, p, size);

    cout << "Delete Operation ->" << endl;
    
     int delP;
    cout << "Position : ";
    cin >> delP;

    deleteTheElement(arr, delP, size);

        return 0;
}

// output
// 6
// 1 2 3 4 5 6
// The average of array is : 3
// Insert Operation ->
// Element : 9
// Position : 3
// Array after inserting ele 9 at position 3 is :
// 1 2 3 9 4 5 6
// Delete Operation ->
// Position : 1
// Array after deleting at position 1 is :
// 1 3 9 4 5 6