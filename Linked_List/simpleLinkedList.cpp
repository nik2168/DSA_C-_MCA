#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insert(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteNode(int key)
    {
        Node *temp = head;
        Node *prev = nullptr;

        if (temp != nullptr && temp->data == key)
        {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
            return;

        prev->next = temp->next;
        delete temp;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();

    list.deleteNode(20);
    list.display();

    return 0;
}