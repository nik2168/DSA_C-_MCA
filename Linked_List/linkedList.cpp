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

class list
{

public:
    node *head;
    node *tail;

    int size;

    list()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertAtTail(int val)
    {
        node *newNode = new node(val);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            size++;
            return;
        }

        node * last = tail;
        last->next = newNode;
        newNode->pre = last;
        tail = newNode;
        size++;
    }

    void insertAtHead(int val)
    {

        node *newNode = new node(val);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            size++;
            return;
        }

        node *first = newNode;
        first->next = head;
        head->pre = first;
        head = first;
        size++;
    }

    void insertAtPosition(int pos, int val)
    {

        // optimization
        /*  head->1->2->3->4->5<-tail  */

        node *newNode = new node(val);

        if (head == NULL && tail == NULL)
        {
            if (pos == 0)
            {
                head = newNode;
                tail = newNode;
                return;
            }
            else
            {
                cout << "List is already empty ! try to insert at 0th position" << endl;
                return;
            }
        }

        int itr;

        int mid = size / 2;

        if (pos <= mid)
        {

            itr = 0;
            node * temp = head;

            while (itr <= mid)
            {
                if (itr == pos - 1)
                    break;
                temp = temp->next;
                itr++;
            }

            node * var = temp->next;
            temp->next = newNode;
            newNode->pre = temp;

            newNode->next = var;
            var->pre = newNode;

            return;
        }

        itr = size;
        node *temp = tail;

        while (itr >= mid)
        {
            if (itr == pos - 1)
                break;
            temp = temp->pre;
            itr--;
        }

        node * var = temp->pre;
        temp->pre = newNode;
        var->next = newNode;
        newNode->next = temp;
        newNode->pre = var;
    }

    void printList()
    {
        node *t = head;

        cout<<"head->";
        while (t != NULL)
        {
            cout << t->val << "<->";
            t = t->next;
        }

        cout << "NULL";
        cout<<"<-tail"<<endl;
    }
};

int main()
{

    list l;

    int atEnd;
    cout << "Enter the size of elemets wants to enter at end -> ";
    cin >> atEnd;

    cout << "Enter the elements : ";
    for (int i = 0; i < atEnd; i++)
    {
        int val;
        cin >> val;
        l.insertAtTail(val);
    }

    int atSt;
    cout << "Enter the size of elemets wants to enter at start : ";
    cin >> atSt;

    cout << "Enter the elements : ";
    for (int i = 0; i < atSt; i++)
    {
        int val;
        cin >> val;
        l.insertAtHead(val);
    }

    l.printList();

    int inbtw;
    cout << "Enter the size of elemets wants to enter in between : ";
    cin >> inbtw;

    cout << "Enter the elements : ";
    for (int i = 0; i < inbtw; i++)
    {
        int pos, val;
        cin >> pos;
        cin >> val;
        l.insertAtPosition(pos, val);
    }

    l.printList();

    return 0;
}

// output
// Enter the size of elemets wants to enter at end -> 3
// Enter the elements : 4 5 6
// Enter the size of elemets wants to enter at start : 3
// Enter the elements : 3 2 1
// head->1<->2<->3<->4<->5<->6<->NULL<-tail
// Enter the size of elemets wants to enter in between : 5
// Enter the elements : 0 1 2 2 3 3 4 4 5 9
// head->1<->2<->2<->3<->3<->4<->4<->9<->5<->1<->6<->NULL<-tail

