// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<int> s;
        long long tp,max_area=0;
        int i;
        for(i=0;i<n;)
        {
            if(s.empty() or arr[s.top()]<=arr[i])
            {
                s.push(i++);
            }
            else
            {
                while(!s.empty() and arr[s.top()]>arr[i])
                {
                    tp=s.top();
                    s.pop();
                    
                    long long area_with_top=arr[tp]*(s.empty()?i:i-s.top()-1);
                    max_area=max(max_area,area_with_top);
                    
                }
            }
            
        }
        while(!s.empty())
        {
            tp=s.top();
            s.pop();
            
              
                   long long area_with_top=arr[tp]*(s.empty()?i:i-s.top()-1);
                    max_area=max(max_area,area_with_top);
        }
        return max_area;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
