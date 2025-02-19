#include<iostream>
#include<vector>
using namespace std;


class que{
    public:

  vector<int> arr;
  int front;
  int back;

  que(int size){
     arr.resize(size, -1);
     front = -1;
     back =  -1;
  }

  void pushBack(int val){

      if(front == -1 && back == -1){
           arr[0] = val;
           front = 0;
           back = 0;
      }
      else if(back < arr.size() - 1){
         if(arr[back + 1] == -1){
          arr[back + 1] = val;
          back++;
         }
         else{
            cout<<"queue is full !"<<endl;
         }
      }
      else if(arr[0] == -1){
        arr[0] = val;
        back = 0;
      }
      else{
         cout<<"queue is full !"<<endl;
      }
  }

  void popFront(){
      if(front == -1){
        cout<<"queue is already empty !"<<endl;
      }
      else if(front == back){
        front = -1;
        back = -1;
      }
      else {
          arr[front] = -1;
          if(front == arr.size() - 1){
             front = 0;
             return;
          }
        front++;
      }
  }

  void printQue(){
    cout<<"Array is :" <<endl;
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
  }
    
};




int main(){

 que q(3);
 q.pushBack(1);
 q.pushBack(2);
 q.pushBack(3);
 q.pushBack(4);
//  q.pushBack(5);
 q.popFront();
//  q.popFront();

 q.printQue();

    return 0;
}

// output - queue is full !
// Array is : -1 2 3 