#include <iostream>

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

void ins_btm(Stack* s, char curr)
{
    if(isEmpty(s))push(s, curr);
    else
    {
        char tmp=peek(s);
        pop(s);
        ins_btm(s, curr);
        push(s, tmp);
    }
}

void reversestack(Stack* s)
{
    if(!isEmpty(s))
    {
        char x=peek(s);
        pop(s);
        reversestack(s);
        ins_btm(s, x);
    }
}

int main()
{
    Stack* s=createStack(12);
    char a='a';

    for(int i=0; i<=10; i++)push(s, a++);

    reversestack(s);

    while(!isEmpty(s))
    {
        cout << pop(s) << endl;
    }
    return 0;
}
