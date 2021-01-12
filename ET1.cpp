#include<bits/stdc++.h>
using namespace std;

//INFIX TO POSTFIX

int prec(char c)
{
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '^')
        return 3;
    else
        return 0;
}
int isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return 1;
    else if(c == '(' || c == ')')
        return 1;
    else
        return 0;

}
string infixToPos(string inf)
{
    stack<char> s;
    string pos;
    int l = inf.length();
    for(int i=0;i<l;i++)
    {
        if(!isOperator(inf[i]))
            cout << inf[i];
        else
        {
           if(s.empty())
                s.push(inf[i]);
           else
           {
               if(inf[i] == '(')
                    s.push(inf[i]);
               else if(inf[i] == ')')
               {
                   while(s.top()!= '(')
                   {
                       cout << s.top();
                       s.pop();
                   }
                   s.pop();
               }
               else if(prec(inf[i]) > prec(s.top()))
                    s.push(inf[i]);
               else
               {
                    while (!s.empty()
                            && prec(inf[i]) <= prec(s.top()))
                   {
                       cout << s.top();
                       s.pop();
                   }
                   s.push(inf[i]);
               }
           }
        }
    }
    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }

}

int main()
{
    string in = "((A+B)-C*(D/E))+F";
    infixToPos(in);
    return 0;
}
