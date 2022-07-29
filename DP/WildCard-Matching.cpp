class Solution {
    vector<vector<int> >dp;
    bool rec(string s,string p,int i,int j)
    {
        if(i>=p.size() and j>=s.size())
            return true;
        if(i>=p.size() or j>s.size())
            return false;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(j<s.size() and (p[i]==s[j] or p[i]=='?'))
        {
            return dp[i][j]=rec(s,p,i+1,j+1);
        }
        if(p[i]=='*')
            return dp[i][j]=rec(s,p,i+1,j) or rec(s,p,i,j+1) or rec(s,p,i+1,j+1);
        return dp[i][j]=0;
    }
public:
    bool isMatch(string s, string p) {
        int n=p.size();
        int m=s.size();
        dp=vector<vector<int> >(n+1,vector<int>(m+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            bool flag=true;
            for(int ii=1;ii<=i;ii++)
            {
                if(p[ii-1]!='*')
                {
                    flag=false;
                    break;
                }
            }
            dp[i][0]=flag;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(p[i-1]==s[j-1] or p[i-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[i-1]=='*')
                    dp[i][j]=dp[i-1][j] or dp[i-1][j-1] or dp[i][j-1];
                else
                    dp[i][j]=0;
            }
        }
        return dp[n][m]; 
    }
};
