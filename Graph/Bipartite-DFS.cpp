class Solution {
    bool dfsCheck(int cur,vector<vector<int> >graph,int col[],int c)
    {
        col[cur]=c;
        for(auto nbr:graph[cur])
        {
            if(col[nbr]==-1)
            {
                if(!dfsCheck(nbr,graph,col,1-c))
                    return false;
            }
            else if(c==col[nbr])
                return false;
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
                if(!dfsCheck(i,graph,col,0))
                    return false;
            }
        }
        return true;
    }
};
