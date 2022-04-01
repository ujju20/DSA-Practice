// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    int count(int n)
    {
        int ans=0;
        int p=1;
        while(p<n)
        {
            p*=5;
            ans+=(n/p);
        }
        return ans;
    }
    public:
        int findNum(int n)
        {
        //complete the function here
            int s=1,e=5*n;
             int ans=0;
            while(s<=e)
            {
                int mid=s+(e-s)/2;
                if(count(mid)>=n)
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


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends
