// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    vector<vector<int> >dp;
    int rec(int wt[],int val[],int W,int n,int w,int i)
    {
        
        if(i>=n)
        return 0;
        if(w>W)
        return 0;
        
        if(dp[i][w]!=-1)
        return dp[i][w];
        
        int op1=rec(wt,val,W,n,w,i+1);
        int op2=0;
        if(w+wt[i]<=W)
            op2=val[i]+rec(wt,val,W,n,w+wt[i],i+1);
        
        return dp[i][w]=max(op1,op2);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       dp=vector<vector<int> >(n+1,vector<int>(W+1,0));
       for(int i=1;i<=n;i++)
       {
           for(int w=1;w<=W;w++)
           {
               if(wt[i-1]<=w)
               dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
               else
               dp[i][w]=dp[i-1][w];
           }
       }
       return dp[n][W];
       
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
