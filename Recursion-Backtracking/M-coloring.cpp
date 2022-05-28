// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool isValid(vector<int> adj[],int node,int col,vector<int> color)
{
    for(auto nbr:adj[node])
    {
        if(color[nbr]==col)
        {
            return false;
        }
    }
    return true;
}
bool solve(vector<int> adj[],int m,int n,int col,vector<int> color,int node)
{
    if(node==n)
    {
        return true;
    }
    
    for(int i=1;i<=m;i++)
    {
        if(isValid(adj,node,i,color))
        {
            color[node]=i;
            if(solve(adj,m,n,col,color,node+1))
            {
                return true;
            }
            color[node]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<int> adj[101];
    vector<int> col(101,0);
    for(int i=0;i<101;i++)
    {
        for(int j=0;j<101;j++)
        {
            if(graph[i][j]==1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    return solve(adj,m,n,1,col,0);
    
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
