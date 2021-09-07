// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	
	public:
	bool isValid(int i, int j,int n)
{
    if (i < 0 || i >= n
        || j >= n || j < 0)
        return false;
    return true;
}
	vector<int> downwardDigonal(int n, vector<vector<int>> A)
	{
		// Your code goes here
		vector<int> ans;
		for(int k=0;k<n;k++)
		{
		    ans.push_back(A[0][k]);
		    
		    int i=1;
		    int j=k-1;
		    
		    while(isValid(i,j,n))
		    {
		        ans.push_back(A[i][j]);
		        i++;
		        j--;
		    }
		}
		
		for(int k=1;k<n;k++)
		{
		    ans.push_back(A[k][n-1]);
		    
		    int i=k+1;
		    int j=n-2;
		    
		    while(isValid(i,j,n))
		    {
		        ans.push_back(A[i][j]);
		        i++;
		        j--;
		        
		    }
		}
		return ans;
	}

};

// { Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}
  // } Driver Code Ends
