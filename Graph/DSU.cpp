class DSU{
    public:
    int parent[100001];
    int rank[100001];
    
    
    void makeSet(int n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    int find(int n)
    {
        if(parent[n]==n)
            return n;
        
        return parent[n]=find(parent[n]);
    }
    
    int unioun(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x==y)
            return 0;
        if(rank[x]<rank[y])
        {
            parent[x]=y;
        }
        else if(rank[x]>rank[y])
        {
            parent[y]=x;
        }
        else
        {
            parent[x]=y;
            rank[y]+=1;
        }
        return 1;
    }
};
