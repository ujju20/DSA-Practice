// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    int pre(char c)
    {
        if(c=='^')
        return 3;
        else if(c=='*' or c=='/')
        return 2;
        else if(c=='+' or c=='-')
        return 1;
        else
        return -1;
    }
    //Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        // Your code here
        string result;
        stack<int> st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if((c>='a' and c<='z') or (c>='A' and c<='Z') or (c>='0' and c<='9'))
            {
                result+=c;
            }
            else if(c=='(')
            {
                st.push('(');
                
            }
            else if(c==')')
            {
                while(st.top()!='(')
                {
                    result+=st.top();
                    st.pop();
                }
                st.pop();
                
            }
            else{
                while(!st.empty() and pre(c)<=pre(st.top()))
                {
                    result+=st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty())
        {
            result+=st.top();
            st.pop();
        }
        return result;
    }
};


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string exp;
        cin>>exp;
        Solution ob;
        cout<<ob.infixToPostfix(exp)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
