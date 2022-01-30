// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    vector<vector<int> >ans;
    bool isSafe(vector<vector<bool> > &board, int row, int col)
    {
      int n = board.size();
      for(int i=0; i<row; i++)
        if(board[i][col]) return false;
      for(int i=row, j=col; i>=0 && j>=0; i--,j--)
        if(board[i][j]) return false;
      for(int i=row, j=col; i>=0 && j<n; i--,j++)
        if(board[i][j]) return false;
      return true;
    }
    void rec(int n,int row,vector<int> temp,vector<vector<bool> >b)
    {
        if(row==n)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int col=0;col<n;col++)
        {
            if(isSafe(b,row,col))
            {
                temp.push_back(col+1);
                b[row][col]=true;
                rec(n,row+1,temp,b);
                temp.pop_back();
                b[row][col]=false;
            }
        }
        return;
    }
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<int> temp;
        vector<vector<bool> >b(n,vector<bool>(n,false));
        rec(n,0,temp,b);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
