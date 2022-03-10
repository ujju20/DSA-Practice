// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    bool isInside(int i,int j,int n)
    {
        return i>=0 and j>=0 and i<n and j<n;
    }
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int sr=KnightPos[0]-1;
	    int sc=KnightPos[1]-1;
	    int dr=TargetPos[0]-1;
	    int dc=TargetPos[1]-1;
	    
	    vector<vector<int> >visited(N,vector<int>(N,0));
	    int x,y;
	    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	    
	    queue<vector<int> > q;
	    q.push({sr,sc,0});
	    int steps=0;
	    visited[sr][sc]=1;
	    while(!q.empty())
	    {
	        auto p=q.front();
	        q.pop();
	        
	        if(p[0]==dr and p[1]==dc)
	        return p[2];
	        
	        for(int i=0;i<8;i++)
	        {
	            x=p[0]+dx[i];
	            y=p[1]+dy[i];
	            
	            if(isInside(x,y,N) and visited[x][y]==0)
	            {
	                visited[x][y]=1;
	                q.push({x,y,p[2]+1});
	            }
	            
	        }
	        //steps++;
	    }
	    
	    //return steps;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
