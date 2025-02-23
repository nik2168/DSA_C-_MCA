#include<iostream>
using namespace std;

class node{

public:

int val;
node * next;

node(int val){
    this->val = val;
    next = NULL;
}

};

class list{

    public:
    
    node * head;

    list(){
        head = NULL;
    }

    void insertNode(int val){
        node * newNode = new node(val);

        if(head == NULL){
            head = newNode;
            return;
        }

        node * t = head;
        while(t->next != NULL){
            t = t->next;
        }

        t->next = newNode;

    }

    void printList(){
        node * t = head;

        while(t != NULL){
            cout<<t->val<<"->";
            t = t->next;
        }

        cout<<"NULL"<<endl;
    }

};

int main(){
    
int sizeOfList;

cout<<"Enter the size of List : ";
cin>>sizeOfList;

list l;
for(int i = 0; i < sizeOfList; i++){
    int val;
    cin>>val;
     l.insertNode(val);
}

l.printList();

    return 0;
}


// output
// Enter the size of List : 3
// 1 2 3
// 1->2->3->NULL