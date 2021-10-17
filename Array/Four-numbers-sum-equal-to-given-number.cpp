// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &a, int d) {
        // Your code goes here
        sort(a.begin(),a.end());
        vector<vector<int> > ans;
        int n=a.size();
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int l=j+1;
                int r=n-1;
                int sum=d-a[i]-a[j];
                while(l<r)
                {
                    if(a[l]+a[r]==sum)
                    {
                        vector<int>v({a[i],a[j],a[l],a[r]});
                        sort(v.begin(),v.end());
                        ans.push_back(v);
                        while(l<r and a[l]==a[l+1]) l++;
                        while(l<r and a[r]==a[r-1]) r--; 
                        l++;
                        r--;
                    }
                    else if(a[l]+a[r]>sum)
                    {
                        r--;
                    }
                    else
                    {
                        l++;
                    }
                }
                while(j<=n-3 and a[j]==a[j+1]) j++;
            }
            while(i<=n-4 and a[i]==a[i+1]) i++;
        }
        return ans;
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
