class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int res=nums[0],max_sum=nums[0],min_sum=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0) swap(max_sum,min_sum);
            max_sum=max(nums[i],nums[i]*max_sum);
            min_sum=min(nums[i],nums[i]*min_sum);
            res=max(max_sum,res);
        }
        
        return res;
    }
};
