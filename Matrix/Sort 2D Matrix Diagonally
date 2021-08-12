#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main() {
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }

    vector<int> v;
    for(int row=0;row<n;row++)
    {
        for(int j=0,i=row;i<n and j<m;i++,j++)
        {
            v.push_back(a[i][j]);
        }

        sort(v.begin(),v.end());
        int t=0;
        for(int j=0,i=row;i<n and j<m;i++,j++)
        {
            a[i][j]=v[t++];
        }
        v.clear();

        
    }

    for(int col=0;col<m;col++)
    {
        for(int j=col,i=0;i<n and j<m;i++,j++)
        {
            v.push_back(a[i][j]);
        }

        sort(v.begin(),v.end());
        int t=0;
        for(int j=col,i=0;i<n and j<m;i++,j++)
        {
            a[i][j]=v[t++];
        }
        v.clear();

        
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
