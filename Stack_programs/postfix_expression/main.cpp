#include <bits/stdc++.h>

using namespace std;

int evalPostfix(string s)
{
    int i=0;
    string a;
    stack<int> nums;
    while(i<s.size())
    {
        if(s[i]==' ')
        {
            if(!a.empty())
            {
                int tmp=atoi(a.c_str());
                a.clear();
                nums.push(tmp);
            }
        }
        else if(s[i]=='+')
        {
            int tmp1=nums.top(); nums.pop();
            int tmp2=nums.top(); nums.pop();
            int tmp=tmp1+tmp2;
            nums.push(tmp);
        }
        else if(s[i]=='*')
        {
            int tmp1=nums.top(); nums.pop();
            int tmp2=nums.top(); nums.pop();
            int tmp=tmp1*tmp2;
            nums.push(tmp);
        }
        else if(s[i]=='-')
        {
            int tmp1=nums.top(); nums.pop();
            int tmp2=nums.top(); nums.pop();
            int tmp=tmp2-tmp1;
            nums.push(tmp);
        }
        else
        {
            a.push_back(s[i]);
        }

        i++;
    }
    return nums.top();
}

int main()
{
    string s;
    getline(cin, s);
    cout << "ANS: " << evalPostfix(s);
    return 0;
}
