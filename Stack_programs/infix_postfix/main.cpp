#include <iostream>
#include <string>

using namespace std;

struct Stack
{
    int top;
    int capacity;
    char* arr;
};

Stack* createStack(int n)
{
    Stack* s=new Stack;

    s->top=-1;
    s->capacity=n;
    s->arr=new char[n];

    return s;
}

bool isEmpty(Stack* s)
{
    return (s->top==-1);
}

char peek(Stack* s)
{
    return s->arr[s->top];
}

void push(Stack* s, char a)
{
    s->arr[++s->top]=a;
}

char pop(Stack* s)
{
    if(!isEmpty(s))return s->arr[s->top--];
    else return '!';
}

bool isOperand(char a)
{
    return ((a>='a' && a<='z') || (a>='A' && a<='Z'));
}

int prec(char ch)
{
    if(ch=='+' || ch=='-')return 1;
    else if(ch=='*' || ch=='/')return 2;
    else return -1;
}

void infixtopostfix(string s)
{
    string ans;

    Stack* stk=createStack(s.size()+1); // +1 is for extra memory

    for(int i=0; i<s.size(); i++)
    {
        if(isOperand(s[i]))ans.push_back(s[i]);
        else if(s[i]=='(')push(stk, s[i]);
        else if(s[i]==')')
        {
            while(!isEmpty(stk) && peek(stk)!='(')ans.push_back(pop(stk));

            pop(stk);
        }
        else
        {
            while(!isEmpty(stk) && prec(s[i]) <= prec(peek(stk)))
            {
                ans.push_back(pop(stk));
            }
            push(stk, s[i]);
        }
    }

    while(!isEmpty(stk))ans.push_back(pop(stk));

    cout << ans << endl;
}

int main()
{
    cout << "Enter the expression" << endl;
    string expr;
    getline(cin, expr);
    infixtopostfix(expr);
    return 0;
}
