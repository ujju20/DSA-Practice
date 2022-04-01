// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    bool check(int a[],int n,int sum,int m)
    {
        int s=1;
        long long int t=0;
        for(int i=0;i<n;i++)
        {
            if(t+a[i]>sum)
            {
                s++;
                t=a[i];
                if(s>m)
                return false;
            }
            else
            {
                t+=a[i];
            }
        }
        return true;;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        //code here
        int s=0,e;
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            s=max(s,a[i]);
        }
        
        e=sum;
        int ans=INT_MAX;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(check(a,n,mid,m))
            {
                ans=min(ans,mid);
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
