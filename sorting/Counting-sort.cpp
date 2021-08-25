#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void counting_sort(int a[],int n,int m)
{
    int count[m+1]={0};
    for(int i=0;i<n;i++)
    {
        count[a[i]]++;

    }
    for(int i=1;i<=m;i++)
    {
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=0;i<n;i++)
    {
        output[--count[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++)
    {
        a[i]=output[i];
    }
}
int main() {
    int n;
    cin>>n;
    int a[n];
    int m=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m=max(m,a[i]);
    }

    counting_sort(a,n,m);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
