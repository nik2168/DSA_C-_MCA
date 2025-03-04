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

// output : 
/*
Infix : a+b*(c^d-e)^(f+g*h)-i
Postfix : abcd^e-fgh*+^*+i-%  
*/


// Algorithm :
/*
Algorithm to convert infix expression to postfix expression:

1. Initialize an empty stack `st` for operators and an empty string `postfix` for the result.

2. Iterate over each character `ch` in the input infix expression `s`:
   a. If `ch` is an operand (alphanumeric character), append it to `postfix`.
   b. If `ch` is an opening parenthesis '(', push it onto the stack `st`.
   c. If `ch` is a closing parenthesis ')', pop from `st` and append to `postfix` until an opening parenthesis '(' is encountered on the stack. Pop and discard the '(' from the stack.
   d. If `ch` is an operator:
      i. While the stack is not empty, and the precedence of the operator at the top of the stack is greater than or equal to the precedence of `ch`, pop from `st` and append to `postfix`.
      ii. Push `ch` onto the stack `st`.

3. After the entire infix expression has been processed, pop and append all remaining operators from the stack `st` to `postfix`.

4. The `postfix` string now contains the postfix expression equivalent of the given infix expression.
*/

