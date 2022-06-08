// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    priority_queue<int> ma;
    priority_queue<int,vector<int>,greater<int> >mi;
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(ma.empty())
        {
            ma.push(x);
        }
        else if(x<ma.top())
        {
            ma.push(x);
        }
        else
        {
            mi.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(ma.size()>mi.size()+1)
        {
            mi.push(ma.top());
            ma.pop();
        }
        else if(mi.size()>ma.size())
        {
            ma.push(mi.top());
            mi.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        double ans=0;
        if(ma.size()==mi.size())
        {
            ans=(ma.top()+mi.top())/2;
        }
        else
        {
            ans=ma.top();
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends
