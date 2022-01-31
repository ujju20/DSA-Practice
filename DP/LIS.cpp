int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    int dp[n]={0};
    int len=1;
    dp[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        auto l=lower_bound(dp,dp+len,arr[i]);
        if(l==dp+len)
        {
            dp[len++]=arr[i];
        }
        else
        {
            *l=arr[i];
        }
       
    }
     return len;
}
