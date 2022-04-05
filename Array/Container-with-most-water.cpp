class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int ans=0;
        
        int i=0,j=n-1;
        
        while(i<j)
        {
            int a=min(h[i],h[j]);
            int b=j-i;
            ans=max(ans,a*b);
            
            if(h[i]<h[j])
                i++;
            else j--;
        }
        return ans;
    }
};
