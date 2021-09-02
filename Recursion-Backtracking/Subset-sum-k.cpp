void solve(vector<int> a,int n,int i,int k,vector<vector<int> > &ans,vector<int> v)
{
    if(i==n)
    {
        if(k==0)
        {
            ans.push_back(v);
            return;
            
        }
        else
        {
            return;
        }
    }
        
        solve(a,n,i+1,k,ans,v);
        v.push_back(a[i]);
        solve(a,n,i+1,k-a[i],ans,v);
        
        
    
    
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int> > ans;
    vector<int>v;
    solve(arr,n,0,k,ans,v);
    return ans;
}
