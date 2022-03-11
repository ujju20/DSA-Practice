// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int key[V],mst[V],parent[V];
        for(int i=0;i<V;i++)
        {
            key[i]=INT_MAX;
            //parent[i]=-1;
            mst[i]=0;
        }
        priority_queue<pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > > pq;
        pq.push({0,0});
        key[0]=0;
        parent[0]=-1;
        int cost=0;
        while(!pq.empty())
        {
            int u=pq.top().second;
            pq.pop();
            
            mst[u]=1;
            for(auto x:adj[u])
            {
                int v=x[0];
                int wt=x[1];
                //cout<<x.size()<<" ";
                if(mst[v]==0 and wt<key[v])
                {
                    key[v]=wt;
                    parent[v]=u;
                    pq.push({key[v],v});
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            cost+=key[i];
        }
        return cost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
