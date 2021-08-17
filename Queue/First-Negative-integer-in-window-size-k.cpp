// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends




vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int N, long long int k) {
                                                 
    deque<int> q;
    vector<long long> v;
    int i;
    for(i=0;i<k;i++)
    {
        if(a[i]<0)
        q.push_back(i);
    }
    for(;i<=N-1;i++)
    {
        if(!q.empty())
        {
            v.push_back(a[q.front()]);
        }
        else
        {
            v.push_back(0);
        }
        
        while((!q.empty()) and q.front()<i-k+1)
        {
            q.pop_front();
        }
        
        if(a[i]<0)
        q.push_back(i);
        
    }
    
    if(!q.empty())
    {
        v.push_back(a[q.front()]);
    }
    else
    {
        v.push_back(0);
    }
    
  
    return v;
                                                 
 }
