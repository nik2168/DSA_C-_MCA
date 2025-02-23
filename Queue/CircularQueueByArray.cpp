#include <iostream>
#include <vector>
using namespace std;

class que
{
public:
    vector<int> arr;
    int front;
    int back;

    que(int size)
    {
        arr.resize(size, -1);
        front = -1;
        back = -1;
    }

    void pushBack(int val)
    {

        if (front == -1 && back == -1)
        {
            arr[0] = val;
            front = 0;
            back = 0;
        }
        else if (back < arr.size() - 1)
        {
            if (arr[back + 1] == -1)
            {
                arr[back + 1] = val;
                back++;
            }
            else
            {
                cout << "queue is full !" << endl;
            }
        }
        else if (arr[0] == -1)
        {
            arr[0] = val;
            back = 0;
        }
        else
        {
            cout << "queue is full !" << endl;
        }
    }

    void popFront()
    {
        if (front == -1)
        {
            cout << "queue is already empty !" << endl;
        }
        else if (front == back)
        {
            front = -1;
            back = -1;
        }
        else
        {
            arr[front] = -1;
            if (front == arr.size() - 1)
            {
                front = 0;
                return;
            }
            front++;
        }
    }

    void printQue()
    {
        cout << "Queue is :" << endl;
        for (int i : arr)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{

int n;
cout<<"Enter the size of queue : ";
cin>>n;

que q(n);

for(int i = 0; i < n; i++){
    int val;
    cin>>val;
    q.pushBack(val);
}

q.popFront();

q.printQue();

    return 0;
}

// Enter the size of queue : 6
// 1 2 3 4 5 6 
// Queue is : -1 2 3 4 5 6