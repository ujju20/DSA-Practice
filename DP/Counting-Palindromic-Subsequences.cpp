// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    vector<vector<long long int> >dp;
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       int n=str.size();
       int mod=1e9+7;
       dp=vector<vector<long long int> >(n,vector<long long int>(n,0));
       for(int i=0;i<n;i++)
       {
           dp[i][i]=1;
       }
       for(int l=2;l<=n;l++)
       {
           for(int i=0;i<=n-l;i++)
           {
               int j=l+i-1;
               if(str[i]==str[j])
               {
                   dp[i][j]=(dp[i+1][j]%mod+dp[i][j-1]%mod+1)%mod;
               }
               else
               {
                   dp[i][j]=(mod+dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1])%mod;
               }
           }
       }
       
       return dp[0][n-1];
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends
