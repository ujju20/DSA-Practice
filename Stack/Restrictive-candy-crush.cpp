// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        // Your code goes here
        if(k==1)
        {
            return "";
        }
        stack<pair<char,int> > st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push({s[i],1});
            }
            else if(st.top().first==s[i])
            {
                st.push({s[i],st.top().second+1});
                if(st.top().second==k)
                {
                    int x=k;
                    while(x)
                    {
                        st.pop();
                        x--;
                    }
                }
            }
            else
            {
                st.push({s[i],1});
            }
        }
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }


};

// { Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}  // } Driver Code Ends
