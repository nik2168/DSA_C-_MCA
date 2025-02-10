#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int main(){

    string s = "257*+6-";

    stack<int> st;

  for(int i = 0; i < s.size(); i++){
    if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
        st.push(s[i] - '0');
        cout<<s[i] - '0'<<endl;
    }
    else {
         int a = st.top();
         st.pop();
         int b = st.top();
         st.pop();
         int res;
         if(s[i] == '*')  res = a * b;
         if(s[i] == '+') res = a + b;
         if(s[i] == '-') res = a - b;
         if(s[i] == '/') res = a/b;
         st.push(res);
    }
}

cout<<st.top();

    return  0;
}