// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
    bool solve(int a[],int n,int k,int currSum,int cnt,vector<int> &vis,int sum)
    {
        if(cnt==k-1)
        {
            return true;
        }
        if(currSum>sum)
        {
            return false;
        }
        if(currSum==sum)
        {
            return solve(a,n,k,0,cnt+1,vis,sum);
        }
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                if(solve(a,n,k,currSum+a[i],cnt,vis,sum))
                {
                    return true;
                }
                vis[i]=false;
            }
        }
        return false;
    }
  public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         if(k==1)
         {
             return true;
         }
         if(k>n)
         {
             return false;
         }
         int sum=0;
         for(int i=0;i<n;i++)
         {
             sum+=a[i];
         }
         if(sum%k!=0)
         {
             return 0;
         }
         vector<int> vis(n,0);
         return solve(a,n,k,0,0,vis,sum/k);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends
