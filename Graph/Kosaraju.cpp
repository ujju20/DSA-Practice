// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    void dfs(vector<int> adj[],stack<int>& s,vector<bool> &vis,int node)
    {
        vis[node]=true;
        for(auto nbr:adj[node])
        {
            if(!vis[nbr])
                dfs(adj,s,vis,nbr);
        }
        s.push(node);
    }
     void revDFS(int node,vector<int> tra[],vector<bool> &vis)
    {
        vis[node]=true;
        for(auto nbr:tra[node])
        {
            if(!vis[nbr])
                revDFS(nbr,tra,vis);
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        // Step-1- Do the TopoSort of the given graph
        stack<int> s;
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(adj,s,vis,i);
            }
        }
        
        //Step-2 Do the Transpose of the given graph
        vector<int> transpose[V];
        for(int i=0;i<V;i++)
        {
            vis[i]=false;
            for(auto it:adj[i])
                transpose[it].push_back(i);
        }
        
        //Do the reverse DFS of the transposed Graph
        int ans=0;
        while(!s.empty())
        {
            int node=s.top();
            s.pop();
            if(!vis[node])
            {
                ans++;
                revDFS(node,transpose,vis);
            }
        }
        return ans;
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
