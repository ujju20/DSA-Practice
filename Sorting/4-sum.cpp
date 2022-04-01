// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &a, int k) {
        // Your code goes here
         int n=a.size();
        vector<vector<int> >ans;
        if(n<4)
        {
            return ans;
        }
        sort(a.begin(),a.end());
        
        for(int i=0;i<n-3;i++)
        {
            if(i>0 and a[i]==a[i-1])
                continue;
            for(int j=i+1;j<n-2;j++)
            {
                 if(j>i+1 and a[j]==a[j-1])
                    continue;
                if(i==j)
                    continue;
                int l=j+1,r=n-1;
                
                while(l<r)
                {
                    long long int aa=a[i],b=a[j],c=a[l],d=a[r];
                    long long int sum=aa+b+c+d;
                    if(sum==k)
                    {
                        vector<int> v({(int)aa,(int)b,(int)c,(int)d});
                        sort(v.begin(),v.end());
                        ans.push_back(v);
                        while(l<r and a[l]==a[l+1]) l++;
                        while(l<r and a[r]==a[r-1]) r--; 
                        l++;
                        r--;
                    }
                    else if(sum>k)
                    {
                        r--;
                    }
                    else
                    {
                        l++;
                    }
                }
            }
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
