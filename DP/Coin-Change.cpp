// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    vector<vector<long long int> >dp;
    long long int rec(int a[],int n,int m,int amt,int i)
    {
        if(amt==m)
        return 1;
        
        if(i>=n or amt>m)
        return 0;
        
        if(dp[i][amt]!=0)
        {
            return dp[i][amt];
        }
        
        int op1=rec(a,n,m,amt+a[i],i);
        int op2=rec(a,n,m,amt,i+1);
        
        return dp[i][amt]=op1+op2;
    }
  public:
    long long int count(int a[], int n, int m) {

        // code here.
        dp=vector<vector<long long int> >(n,vector<long long int>(m+1,0));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int amt=1;amt<=m;amt++)
            {
                if(a[i]<=amt)
                {
                    if(i>0)
                    dp[i][amt]=dp[i][amt-a[i]]+dp[i-1][amt];
                    else
                    dp[i][amt]=dp[i][amt-a[i]];
                }
                else
                {
                    if(i>0)
                    dp[i][amt]=dp[i-1][amt];
                    else
                    dp[i][amt]=0;
                }
            }
        }
        return dp[n-1][m];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends
