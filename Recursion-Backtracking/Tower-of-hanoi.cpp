void solve(int n,int a,int b,int c,vector<vector<int> >& v)
{
    //base case
    if(n==1)
    {
        v.push_back({a,c});
        return;
        
    }
    
    solve(n-1,a,c,b,v);
    v.push_back({a,c});
    solve(n-1,b,a,c,v);
}

vector<vector<int>> towerOfHanoi(int n)
{
    //    Write your code here.
    vector<vector<int> >v;
    solve(n,1,2,3,v);
    return v;
    
    
}
