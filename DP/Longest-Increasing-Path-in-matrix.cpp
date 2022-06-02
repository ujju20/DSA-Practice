// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int dfs(vector<vector<int> > &mat,vector<vector<int> >&dp,int i,int j,int m,int n)
    {
        if(i>=m or i<0 or j<0 or j>=n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int ans=1;
        for(int k=0;k<4;k++)
        {
            int x=i+dx[k],y=j+dy[k];
            if(x>=0 and y>=0 and x<m and y<n and mat[x][y]>mat[i][j])
                ans=max(ans,1+dfs(mat,dp,x,y,m,n));
        }
        return dp[i][j]=ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        // Code here
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int> > dp(m,vector<int>(n,-1));
        //dp[0][0]=1;
        int ans=INT_MIN;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               ans=max(ans,dfs(mat,dp,i,j,m,n));
            }
        }
        return ans;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
