#include <iostream>
using namespace std;

class node
{
public:
    int val;
    node *next;
    node *pre;

    node(int val)
    {
        this->val = val;
        next = NULL;
        pre = NULL;
    }
};

class circularList
{
public:
    node *head;
    node *tail;

    circularList()
    {
        head = NULL;
        tail = NULL;
    }

    void insertNode(int val, bool flag)
    {
        node *newNode = new node(val);

        if (head == NULL && tail == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        if (flag)
        {
            node *t = head;
            newNode->next = t;
            t->pre = newNode;
            head = newNode;
            tail->next = newNode;
            newNode->pre = tail;
            return;
        }

        node *t = tail;

        newNode->next = head;
        newNode->pre = t;

        t->next = newNode;
        head->pre = newNode;
        tail = newNode;
    }

    void deleteNode(bool flag)
    {
        if (head == NULL)
        {
            cout << "list is empty !";
            return;
        }

        if (flag)
        {
            node *t = head;
            head = t->next;
            head->pre = tail;
            tail->next = head;
            return;
        }
        node *t = tail;
        tail = t->pre;
        tail->next = head;
        head->pre = tail;
    }

    void printCircularList()
    {
        node *t = head;

        cout << "head<->";
        while (t != tail)
        {
            cout << t->val << "<->";
            t = t->next;
        }

        cout << t->val << "<->tail" << endl;
    }
};

int main()
{

    circularList l;

    l.insertNode(3, true);
    l.insertNode(2, true);
    l.insertNode(1, true);
    l.insertNode(4, false);
    l.insertNode(5, false);

    l.printCircularList();
    l.deleteNode(true);
    l.deleteNode(false);
    l.printCircularList();

    return 0;
}

/*
head<->1<->2<->3<->4<->5<->tail
head<->2<->3<->4<->tail
*/