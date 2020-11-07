class Solution{
    public:
        int removeDuplicates(vector<int>& nums) {
            int j=1, n=nums.size();
            if(n==0) return 0;
            int tmp=nums[0];
            for(int i=1;i<n;i++){
                if(nums[i]!=tmp){
                    tmp=nums[i];
                    nums[j]=nums[i];
                    j++;
                }
            }
            return j;
        }
};
