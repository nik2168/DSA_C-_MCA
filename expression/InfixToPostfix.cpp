#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int prec(char val)
{
    if (val == '^')
        return 4;
    if (val == '*' || val == '/')
        return 3;
    if (val == '+' || val == '-')
        return 2;
    return 1;
}

bool isChar(char val)
{
    if (val >= 'a' && val <= 'z' || val >= 'A' && val <= 'Z')
        return true;
    return false;
}

string infixToPostFixConverter(string &s)
{

    stack<char> st;

    string postfix;


    for (int i = 0; i < s.length(); i++)
    {

        char ch = s[i];

      if (isChar(ch))
        {
            postfix += ch; // concat in postfix if its a char
        }
        else if (ch == '(')
        {
            st.push(ch);  // push in st if its a opening bracket
        }

        else if (ch == ')') // if its a closing bracket
        {
            while (st.top() != '(')  // pop from st till we reach the opening bracket
            {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // pop the opening bracket form stack !
        }

        else
        {
            // cout<<"Here ... : "<<ch<<endl;
            if(st.empty()) st.push(ch);
            else if (prec(st.top()) < prec(ch)) st.push(ch);
            else{


                while (!st.empty())
                {

                    if(st.top() == '(') break;
                    postfix += st.top();
                    st.pop();
                }
                st.push(ch);
            }
    
        }
       if(st.size()) cout<<st.top()<<" "<<postfix<<endl;
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{

    string infix = "a+b*(c^d-e)^(f+g*h)-i";

    string postfix = infixToPostFixConverter(infix);

    cout << "Infix : " << infix << endl;
    cout << "Postfix : " << postfix;

    return 0;
}