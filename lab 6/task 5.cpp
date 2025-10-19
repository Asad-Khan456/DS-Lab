#include <iostream>
#include <stack>
#include <string>
using namespace std;
int precedence(char op){
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
string infixToPostfix(string infix){
    stack<char> s;
    string postfix = "";
    for(int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];
        if(ch >= '0' && ch <= '9'){
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if(!s.empty()) s.pop();
        }
        else{
            while(!s.empty() && precedence(ch) <= precedence(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty()){
        postfix += s.top();
        s.pop();
    }
    return postfix;
}
int evaluatePostfix(string postfix){
    stack<int> s;
    for(int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];
        if(ch >= '0' && ch <= '9'){
            s.push(ch - '0');
        }
        else{
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            int result;
            if (ch == '+') result = a + b;
            else if (ch == '-') result = a - b;
            else if (ch == '*') result = a * b;
            else if (ch == '/') result = a / b;
            s.push(result);
        }
    }
    return s.top();
}
int main(){
    string infix;
    cout << "Enter infix expression (single-digit numbers only): ";
    cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << "postfix expression: " << postfix << endl;
    int result = evaluatePostfix(postfix);
    cout << "result after evaluation: " << result << endl;
    return 0;
}



