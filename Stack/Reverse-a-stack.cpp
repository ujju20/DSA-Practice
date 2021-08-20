#include <bits/stdc++.h>
using namespace std;
#define ll long long 
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
void reverseStack(stack<int> &s)
{
    if(s.empty()) return ;

    int a=s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,a);
    
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
    reverseStack(s);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}

//This Method of reverse uses recursion and extra space of functional call stack but if we want to do it without recursion and without using any extra space we can do it
// using the Following Technique

/* 1.We have to create our own stack class using Linked List
   2. We can create a method in our stack class which just reverses a Linked List
*/
