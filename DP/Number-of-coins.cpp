// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

vector<vector<int> >dp;
int rec(int a[],int n,int v,int i)
{
    if(v==0)
    return 0;
    
    
    int res=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=v)
        {
            int sub_res=rec(a,n,v-a[i],i);
            if(sub_res!=INT_MAX and sub_res+1<res)
            {
                res=1+sub_res;
            }
        }
    
    }
    return res;
}

class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<int> dp(V+1,INT_MAX);
	    dp[0]=0;
	    for(int i=1;i<=V;i++)
	    {
	        for(int j=0;j<M;j++)
	        {
	            if(coins[j]<=i)
	            {
	                int sub_res=dp[i-coins[j]];
	                if(sub_res!=INT_MAX and 1+sub_res<dp[i])
	                {
	                    dp[i]=sub_res+1;
	                }
	            }
	        }
	    }
	    return dp[V]==INT_MAX?-1:dp[V];
	    
	} 
	  
};



// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
