#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
const ld Pi = 3.141592653;
const ll mod = 1e9 + 9;
#define hihi ll t;cin>>t;while(t--)
vector <ll> primes;
void rec(vector<vector<int> > a,int i,int j,vector<vector<int> > &ans,vector<int> temp)
{
   
   if(i==a.size()-1)
   {
       for(int k=j;k<a[0].size();k++)
       {
           temp.push_back(a[i][k]);
       }
       ans.push_back(temp);
       return;
   }
    if(j==a[0].size()-1)
   {
       for(int k=i;k<a.size();k++)
       {
           temp.push_back(a[k][j]);
       }
       ans.push_back(temp);
       return;
   }

    temp.push_back(a[i][j]);
    rec(a,i+1,j,ans,temp);
    rec(a,i,j+1,ans,temp);
    temp.pop_back();
    return;
}
int main()
{
 ll t;
 cin>>t;
 while(t--)
 {
     int m,n;
     cin>>m>>n;
     vector<vector<int> >a(m,vector<int>(n));
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         cin>>a[i][j];
     }
     vector<vector<int> > ans;
     vector<int> temp;
     rec(a,0,0,ans,temp);
     for(auto x:ans)
     {
         for(auto y:x)
         cout<<y<<" ";
         cout<<endl;
     }
     cout<<endl;
 }
 
  return 0;
}
