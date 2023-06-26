#include<bits/stdc++.h>
using namespace std;
bool IsValid (char expression[])
{
    int n = strlen(expression);
    stack<int> stackChar;
    for (int i = 0; i < n; ++i)
    {
        if(expression[i] == '{' || expression[i] == '[' || expression[i] == '(')
            stackChar.push(expression[i]);
        else if (expression[i] == '}' || expression[i] == ']' || expression[i] == ')')
        {
            expression[i]-=((expression[i] == '}' || expression[i] == ']') ? 2 :1);
            if(stackChar.empty() || stackChar.top()!= expression[i])
               return false;
            else
                stackChar.pop();
        }
    }
    return stackChar.empty();
}
int main()
{
    cout << "Please type the parenthesis expression "<< "then press ENTER!" << endl;
    char expr[1000];
    cin >> expr;
    cout << "The " << expr << " expression is " << (!IsValid(expr) ? "in":"") <<"valid"<< endl;
}