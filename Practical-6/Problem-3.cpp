#include <iostream>
#include <stack>
using namespace std;

int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;

    if(op == '*' || op == '/')
        return 2;

    if(op == '^')
        return 3;

    return 0;
}

void infixToPostfix(string exp)
{
    stack<char> s;
    string postfix = "";

    for(int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

    
        if(isalnum(ch))
        {
            postfix += ch;
        }

        else if(ch == '(')
        {
            s.push(ch);
        }

      
        else if(ch == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

           
            if(!s.empty())
            {
                s.pop();
            }
        }

       
        else
        {
            while(!s.empty() &&
                  s.top() != '(' &&
                  precedence(s.top()) >= precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while(!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix expression: " << postfix << endl;
}

int main() 
{
    string expression;

    cout << "Enter infix expression: ";
    cin >> expression;

    infixToPostfix(expression);

    return 0;
}  