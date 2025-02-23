#include<iostream>
#include<vector>
using namespace std;

class queuee{
    public:

    vector<int> arr;
    int front;
    int back;

    queuee(int size){
        arr.resize(size, -1);
        front = -1;
        back = -1;
    }

    void push(int val){
        if(back == -1 && front == -1){
             front = 0;
             back = 0;
             arr[back] = val;
             return;
        }
        else if(back == arr.size() - 1){
            cout<<"Queue is full !"<<endl;
        }
        else{
        arr[++back] = val;
        }
    }

    void pop(){
        if(front == -1 && back == -1){
            cout<<"Queue is empty !"<<endl;
            return;
        }
        else{
         for(int i = 0; i < arr.size() - 1; i++){
            arr[i] = arr[i + 1];
         }
         arr[arr.size() - 1] = 0;
        }
    }


    void printQueue(){
        for(int i = 0; i < arr.size(); i++){
            cout<<arr[i]<<", ";
        }
        cout<<endl;
    }

};

int main(){

    int n;
    cout<<"Enter the queue size : ";
    cin>>n;

    queuee q(n);

    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        q.push(val);
    }

    q.pop();

    q.printQueue();

    return 0;
}


// output
// Enter the queue size : 3
// 1 2 3
// 2, 3, 0, 