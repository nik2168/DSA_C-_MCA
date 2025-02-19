#include<iostream>
using namespace std;

class node{
    public:

    int val;
    node * next;
    
    node (int val){
        node * next = nullptr;
        this->val = val;
    }

};

class list{
    public:

    node * head;

    list(){
        head = nullptr;
    }

    void insertAtTail(int val){
        node * newNode = new node(val);

        if(head == nullptr) {
            head = newNode;
            return;
        }

        node * t = head;

        while(t->next != nullptr){
            t = t->next;
        }

        t->next = newNode;

        return;
    }

    void insertAtHead(int val){
        node * newNode = new node(val);

        if(head == nullptr){
            head = newNode;
            return;
        }
        node * t = head;
        head = newNode;
        newNode->next = t;
        
        return;
    }

    void printList(){
        node * t = head;

        while(t->next != nullptr){
            cout<<t->val<<"->";
            t = t->next;
        }
        cout<<t->val<<"->NULL"<<endl;
    }

    void removeFromHead(){

        if(head == nullptr) {
            cout<<"already empty error!";
            return;
        }

        node * t = head;
        head = t->next;
        
        delete t; // free up the memory
    }
};

class stackk{
    public:

    int size;
    int cur_size;
    list s;

    stackk(int size){
        this->size = size;
        cur_size = 0;
    }

    void push(int val){
        if(size <= cur_size) {
            cout<<"stack Overflow !"<<endl;
            return;
        }
         s.insertAtHead(val);
              cur_size++;
    }

    void pop(){
        if(cur_size <= 0){
       cout<<"stack underflow !"<<endl;
       return;
        }
     s.removeFromHead();
     cur_size--;
    }

    int top(){
      
       return s.head->val;
    }

    void printStack(){
        s.printList();
    }

};

int main(){

stackk s(3);

s.push(1);
s.push(2);
s.push(3);
s.push(4);

cout<<s.top()<<endl;
s.pop();
cout<<s.top()<<endl;

s.printStack();

    return 0;
}

// output
// stack Overflow !
// 3 
// 2
// 2->1->NULL