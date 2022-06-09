// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          //code here
          priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> >>,greater<pair<int,pair<int,int> > > > pq;
          int mx=INT_MIN,mi=INT_MAX,low=0,high=0,range=INT_MAX;
          for(int i=0;i<k;i++)
          {
              pq.push({arr[i][0],{i,0}});
              mx=max(mx,arr[i][0]);
              //mi=min(mi,arr[i][0]);
          }
          while(true)
          {
              auto p=pq.top();
              
              int min1=p.first;
              if(range>mx-min1)
              {
                  mi=min1;
                  low=mi;
                  high=mx;
                  range=mx-mi;
              }
              int ni=pq.top().second.first;
              int nj=pq.top().second.second;
              pq.pop();
              if(nj==n-1)
              {
                  break;
              }
              pq.push({arr[ni][nj+1],{ni,nj+1}});
              if(arr[ni][nj+1]>mx)
              {
                  mx=arr[ni][nj+1];
              }
          }
          return {low,high};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends
