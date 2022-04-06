class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod=1e9+7;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n-2;i++)
        {
            int l=i+1,r=n-1;
            while(l<r)
            {
                int sum=arr[i]+arr[l]+arr[r];
                if(sum==target)
                {
                    int c1=1,c2=1;
                    while(l<r and arr[l]==arr[l+1])
                    {
                        c1++;
                        l++;
                    }
                     while(l<r and arr[r]==arr[r-1])
                    {
                        c2++;
                        r--;
                    }

                    if(l==r)
                    {
                        int m=(c1%mod)*(c1-1)%mod;
                        m/=2;
                        ans=(ans+m)%mod;
                    }
                    else
                    {
                        ans=(ans%mod+((c1%mod)*(c2%mod))%mod)%mod;
                    }
                    l++;
                    r--;
                }
                else if(sum>target)
                    r--;
                else
                    l++;
            }
        }
        return ans;
                         
    }
};
