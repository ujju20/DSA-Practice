// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    vector<int> dp;
    bool isPalindrome(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--])
            {
                return false;
            }
        }
        return true;
    }
    int rec(string s,int n,int i,string temp)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int minCost=INT_MAX;
        for(int j=i;j<n;j++)
        {
            if(isPalindrome(s,i,j))
            {
                int cost=1+rec(s,n,j+1,temp);
                 minCost=min(minCost,cost);
            }
           
        }
        return dp[i]=minCost;
    }
public:
    int palindromicPartition(string s)
    {
        // code here
        int n=s.size();
        dp.resize(n,-1);
        string temp;
        return rec(s,n,0,temp)-1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
