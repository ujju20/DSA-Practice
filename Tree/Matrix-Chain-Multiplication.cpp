// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    vector<vector<int> >dp;
    int rec(vector<int> a,int i,int j)
    {
        if(i==j)
        return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int res=INT_MIN;   
        for(int k=i;k<j;k++)
        {
            int cost=a[i-1]*a[k]*a[j]+rec(a,i,k)+rec(a,k+1,j);
            if(res<cost)
                res=cost;
        }
        
        return dp[i][j]=res;
    }
    public:
        int maxCoins(vector <int> &a,int n)
        {
                // write your code here
                vector<int> arr;
                arr.push_back(1);
                for(int i=0;i<n;i++)
                {
                    arr.push_back(a[i]);
                }
                arr.push_back(1);
                dp=vector<vector<int> >(n+2,vector<int>(n+2,0));
                for(int i=n+1;i>=1;i--)
                {
                    for(int j=i+1;j<=n+1;j++)
                    {
                        for(int k=i;k<j;k++)
                        {
                            int step=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                            dp[i][j]=max(dp[i][j],step);
                        }
                    }
                }
                return dp[1][n+1];
        }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(a,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends
