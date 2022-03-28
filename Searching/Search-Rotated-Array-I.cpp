class Solution {
public:
    int binarySearch(vector<int> a,int t)
    {
        int s=0,e=a.size()-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(a[mid]==t)
                return mid;
            else if(a[mid]>=a[s])
            {
               if(t>=a[s] and a[mid]>=t)
               {
                   e=mid-1;
               }
                else
                    s=mid+1;
            }
            else
            {
               if(a[e]>=t and a[mid]<=t)
                   s=mid+1;
                else
                    e=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1)
            return nums[0]==target?0:-1;
        return binarySearch(nums,target);
    }
};
