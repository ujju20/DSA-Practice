void rec(vector<int> arr,int curr_sum,int curr_pos,int sum,int ns,int &ans)
{
    if(curr_pos==arr.size())
        return;
    
    if(((arr.size()/2)-ns)>(arr.size()-curr_pos))
        return;
    
    rec(arr,curr_sum,curr_pos+1,sum,ns,ans);
    
    ns++;
    curr_sum+=arr[curr_pos];
    sum-=arr[curr_pos];
    if(ns==arr.size()/2)
    {
        ans=min(ans,abs(curr_sum-sum));
    }
    else
    {
        rec(arr,curr_sum,curr_pos+1,sum,ns,ans);
    }
}
int tugOfWar(vector<int> &arr, int n)
{
    // write your code here
//     if(n==2)
//     {
//         return abs(arr[0]-arr[1]);
//     }
    int sum=0;
    for(auto x:arr)
        sum+=x;
    int ans=INT_MAX;
    rec(arr,0,0,sum,0,ans);
    return ans;
    
}
