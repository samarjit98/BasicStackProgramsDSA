#include <iostream>
#include <stack>

using namespace std;

bool balanced(string s)
{
    stack<char> a;
    int flag=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='{' || s[i]=='[' || s[i]=='(')a.push(s[i]);
        else
        {
            if(s[i]==')')
            {
                char last=a.top();
                a.pop();
                if(last!='(')
                {
                    flag=1; break;
                }
            }
            else if(s[i]=='}')
            {
                char last=a.top();
                a.pop();
                if(last!='{')
                {
                    flag=1; break;
                }
            }
            else if(s[i]==']')
            {
                char last=a.top();
                a.pop();
                if(last!='[')
                {
                    flag=1; break;
                }
            }
        }
        if(flag==1)break;
    }
    if(flag==1)return false;
    else if(!a.empty())return false;
    else return true;
}

int main()
{
    string s;
    getline(cin, s);
    if(balanced(s))cout << "BALANCED";
    else cout << "NOT BALANCED";

    return 0;
}
