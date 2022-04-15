class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<bool> >pal(n,vector<bool>(n,0));
        int ans=0;
        string res;
        for(int len=0;len<n;len++)
        {
            for(int i=0,j=len;i<n and j<n;i++,j++)
            {
                if(len==0)
                {
                    pal[i][j]=1;
                }
                else if(len==1)
                {
                    pal[i][j]=(s[i]==s[j]);
                }
                else
                {
                    pal[i][j]=(s[i]==s[j]) and (pal[i+1][j-1]);
                }
                if(pal[i][j])
                {
                    if(abs(i-j)+1>ans)
                    {
                        ans=abs(i-j)+1;
                        res=s.substr(i,ans);
                    }
                }
            }
        }
        return res;
    }
};
