// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
    bool check(int b[],int n,int m,int no)
{
    long long int sum=0;
    int s=1;
    for(int i=0;i<n;i++)
    {
        if(sum+b[i]>no)
        {
            s++;
            sum=b[i];
            if(s>m)
                return false;
        }
        else
        {
            sum+=b[i];
        }
    }
    return true;
}
  public:
    long long minTime(int b[], int n, int k)
    {
        // code here
        // return minimum time
    long long int s=0,e;
    long long int sum=0;
    //int n=b.size();
    for(int i=0;i<n;i++)
    {
        sum+=b[i];
        s=max(s,(long long int)b[i]);
    }
    e=sum;
    long long int ans=-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(check(b,n,k,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends
