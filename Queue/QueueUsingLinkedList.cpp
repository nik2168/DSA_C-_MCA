#include <iostream>
#include <list>
using namespace std;

class que
{
public:
    list<int> l;

    void pushback(int val)
    {
        l.push_back(val);
        return;
    }

    void popfront()
    {
        l.pop_front();
    }

    int front()
    {
        return l.front();
    }

    int getSize()
    {
        return l.size();
    }

    void printque()
    {
        for (auto i : l)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{

    que q;

    q.pushback(1);
    q.pushback(2);
    q.pushback(3);
    q.pushback(4);

    cout << q.front() << endl;

    cout << q.getSize() << endl;

    q.printque();

    return 0;
}