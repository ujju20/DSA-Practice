class Solution {
    bool bfsCheck(int cur,vector<vector<int> >graph,int col[])
    {
        queue<int> q;
        q.push(cur);
        col[cur]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto n:graph[node])
            {
                if(col[n]==-1)
                {
                col[n]=1-col[node];
                    q.push(n);
                }
                else if(col[n]==col[node])
                    return false;
                
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        int col[v];
        for(int i=0;i<v;i++)
        {
            col[i]=-1;
        }
        
        for(int i=0;i<v;i++)
        {
            if(col[i]==-1)
            {
                if(!bfsCheck(i,graph,col))
                    return false;
            }
        }
        return true;
    }
};
