// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int R, int C) 
    {
        // code here 
        vector<int> ans(R*C);
        vector<vector<bool> > check(R,vector<bool>(C));
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        int r=0,c=0,di=0;
        for(int i=0;i<R*C;i++)
        {
            ans[i]=matrix[r][c];
            check[r][c]=true;
            int cr=r+dr[di];
            int cc=c+dc[di];
            
            if(cr>=0 and cr<R and cc>=0 and cc<C and !check[cr][cc])
            {
                r=cr;
                c=cc;
            }
            else
            {
                di=(di+1)%4;
                r+=dr[di];
                c+=dc[di];
            }
            
        }
        return ans;
    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
