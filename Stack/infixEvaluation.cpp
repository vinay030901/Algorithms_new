#include<bits/stdc++.h>
using namespace std;
int precedence(char optr)
{
    if(optr=='+' || optr =='-') return 1;
    else return 2;
}
int operation(int a,int b,char optr)
{
    if(optr=='+')
    return a+b;
    if(optr =='-')
    return a-b;
    else if(optr =='*')
    return a*b;
    else
    return a/b;
}
int main()
{
    string exp;
    cin>>exp;
    stack<int>operands;
    stack<char>operators;
    for(int i=0;i<exp.length();i++)
    {
        char ch=exp[i];
        if(ch=='('){
            operators.push(ch);
        }
        else if(isdigit(ch)){
            operands.push(ch-'0');
        }
        else if(ch==')'){
            while(operators.top()!='(')
            {
                char optr=operators.top();
                operators.pop();
                int v2=operands.top();
                operands.pop();
                int v1=operands.top();
                operands.pop(); 
                int opv=operation(v1,v2,optr);
                operands.push(opv);
                cout<<opv<<endl;
            }
        }
        else if(ch=='+' || ch=='*' || ch=='-' || ch=='/'){
            
            while(operators.size()>0 || operators.top()!='(' || precedence(ch)<=precedence(operators.top()))
            // ch is wanting higher priority operators to solve first
            {
                char optr=operators.top();
                operators.pop();
                int v2=operands.top();
                operands.pop();
                int v1=operands.top();
                operands.pop(); 
                int opv=operation(v1,v2,optr);
                operands.push(opv);
                cout<<opv<<endl;
            }
            // ch can push itself now
            operators.push(ch);
        }
        else
        {
            cout<<"invalid";
            return 0;
        }
    }
}