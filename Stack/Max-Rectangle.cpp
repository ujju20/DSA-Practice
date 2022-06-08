// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    int maxHist(int a[],int n)
    {
        stack<int> s;
        int ans=0;
        int i;
        for(i=0;i<n;i++)
        {
            while(!s.empty() and a[s.top()]>a[i])
            {
               int top=s.top();
               s.pop();
               int idx=-1;
               if(!s.empty())
               idx=s.top();
               int area=(i-idx-1)*a[top];
               ans=max(ans,area);
            }
            s.push(i);
        }
        while(!s.empty())
        {
               int top=s.top();
               s.pop();
               int idx=-1;
               if(!s.empty())
               idx=s.top();
               int area=(i-idx-1)*a[top];
               ans=max(ans,area);
        }
        return ans;
    }
  public:
    int maxArea(int mat[MAX][MAX], int m, int n) {
        // Your code here
        int ans=0;
        for(int i=0;i<m;i++)
        {
            if(i>0)
            {
                for(int j=0;j<n;j++)
                {
                    if(mat[i][j]!=0)
                    {
                        mat[i][j]+=mat[i-1][j];
                    }
                }
            }
            ans=max(ans,maxHist(mat[i],n));
            
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends
