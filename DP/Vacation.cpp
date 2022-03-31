#include<bits/stdc++.h>
vector<vector<int> >dp;
int rec(vector<vector<int> >p,int i,int n,int last)
{
    int maxi=INT_MIN;
    if(i==n-1)
    {
        for(int j=0;j<=2;j++)
        {
            if(j!=last)
            maxi=max(maxi,p[i][j]);
        }
        return maxi;
    }
    if(dp[i][last]!=-1)
        return dp[i][last];
    
    
    for(int j=0;j<3;j++)
    {
        if(j!=last)
        {
            maxi=max(maxi,p[i][j]+rec(p,i+1,n,j));
        }
    }
    
    return dp[i][last]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    //int n=points.size();
    dp=vector<vector<int> >(n,vector<int>(4,-1));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][1],points[0][0]);
    dp[0][3]=max(points[0][1],max(points[0][2],points[0][0]));
    
    for(int i=1;i<n;i++)
    {
        
        for(int j=0;j<=3;j++)
        {
            dp[i][j]=0;
            int temp=0;
            for(int k=0;k<=2;k++)
            {
                if(k!=j)
                {
                    temp=max(temp,points[i][k]+dp[i-1][k]);
                }
            }
            dp[i][j]=temp;
        }
    }
    return dp[n-1][3];
}
