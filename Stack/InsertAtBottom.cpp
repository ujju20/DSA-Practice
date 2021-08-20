#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void insertAtBottom(stack<int> &s,int data)
{
    if(s.empty())
    {
        s.push(data);
        return;
    }
    int a=s.top();
    s.pop();
    insertAtBottom(s,data);
    s.push(a);
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
    int d;
    cin>>d;
    insertAtBottom(s,d);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
