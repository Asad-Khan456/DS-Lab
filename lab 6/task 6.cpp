#include <iostream>
#include <stack>
#include <string>
using namespace std;
int precedence(char op){
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
bool isOperator(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
string reverseString(const string &str){
    string rev = "";
    for(int i = str.length() - 1; i >= 0; i--){
        rev += str[i];
    }
    return rev;
}
string infixToPrefix(string infix){
    infix = reverseString(infix);
    for(int i = 0; i < infix.length(); i++)
    {
        if(infix[i] == '('){
         infix[i] = ')';
        }
        else if(infix[i] == ')'){
            infix[i] = '(';
        }
    }
    stack<char> s;
    string prefix = "";
    for(int i = 0; i < infix.length(); i++){
        char ch = infix[i];
        if(ch >= '0' && ch <= '9')
        {
            prefix += ch;
        }
        else if(ch == '('){
            s.push(ch);
        }
        else if(ch == ')'){
            while(!s.empty() && s.top() != '(')
            {
                prefix += s.top();
                s.pop();
            }
            if(!s.empty()){
                s.pop();
            }
        }
        else if(isOperator(ch))
        {
            while(!s.empty() && precedence(ch) < precedence(s.top())){
                prefix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while(!s.empty()){
        prefix += s.top();
        s.pop();
    }
    prefix = reverseString(prefix);
    return prefix;
}
int evaluatePrefix(string prefix){
    stack<int> s;
    for(int i = prefix.length() - 1; i >= 0; i--){
        char ch = prefix[i];
        if(ch >= '0' && ch <= '9'){
            s.push(ch - '0');
        }
        else if (isOperator(ch))
        {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
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
    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;
    int result = evaluatePrefix(prefix);
    cout << "Result after evaluation: " << result << endl;
    return 0;
}
