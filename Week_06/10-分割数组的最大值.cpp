class Solution {
public:
    bool match(vector<int>nums, int mid, int m){
        int cnt=1;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){
                sum=nums[i];
                cnt++;
                continue;
            }
            sum+=nums[i];
        }
        return cnt>m;
    }
    int splitArray(vector<int>& nums, int m) {
        long long l=0, r=0, mid;
        for(int i=0;i<nums.size();i++){
            if(l<nums[i]) l=nums[i];
            r+=nums[i];
        }
        while(l<r){
            // 假设每个子数组之和小于mid
            mid=l+(r-l)/2;
            if(match(nums, mid, m)){
                l=mid+1;
            }
            else
                r=mid;
        }
        return l;
    }
};
