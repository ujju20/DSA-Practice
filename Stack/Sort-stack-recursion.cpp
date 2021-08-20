#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ll long long 
void sortedInsert(stack<int> &s,int d)
{
    if(s.empty())
    {
        s.push(d);
        return;
    }
    
    if(d<s.top())
    {
        int a=s.top();
        s.pop();
        sortedInsert(s,d);
        s.push(a);
    }
    else
    {
        s.push(d);
    }
    
}
void sortStack(stack<int> &s)
{
   //Your code here
   if(s.empty()) return ;
   
   int a=s.top();
   s.pop();
   sortStack(s);
   sortedInsert(s,a);
   
}

int main() {
    stack<int> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.push(x);
    }
   sortStack(s);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
