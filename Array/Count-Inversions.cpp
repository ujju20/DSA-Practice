// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    long long int merge(long long arr[],int left,int mid,int right,long long temp[])
    {
        int k=left,i=left,j=mid;
        long long int inv_count=0;
        while(i<mid and j<=right)
        {
            if(arr[i]<=arr[j])
            {
                temp[k++]=arr[i++];
            }
            else
            {
                temp[k++]=arr[j++];
                
                inv_count+=(mid-i);
            }
        }
        while(i<mid)
        {
            temp[k++]=arr[i++];
        }
        while(j<=right)
        {
            temp[k++]=arr[j++];
        }
        for(int i=left;i<=right;i++)
        {
            arr[i]=temp[i];
        }
        return inv_count;
    }
    long long int solve(long long arr[],int s,int e,long long temp[])
    {
        if(s>=e)
        {
            return 0;
        }
        int mid=s+(e-s)/2;
        long long int inv_count=0;
        inv_count+=solve(arr,s,mid,temp);
        inv_count+=solve(arr,mid+1,e,temp);
        inv_count+=merge(arr,s,mid+1,e,temp);
        return inv_count;
    }
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        return solve(arr,0,N-1,temp);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
