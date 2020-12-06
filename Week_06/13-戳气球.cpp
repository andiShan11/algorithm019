class Solution{
    public:
    	static const int N=505;
    	int dp[N][N];
    	int dfs(vector<int>&nums, int l, int r){
            if(l>r) return 0;
            if(dp[l][r]!=-1) return dp[l][r];
            int res=0;
            for(int k=l;k<=r;k++){
                res=max(res, nums[l-1]*nums[k]*nums[r+1]+dfs(nums, l, k-1)+dfs(nums, k+1, r));
            }
            
            return dp[l][r]=res;
        }
    	int maxCoins(vector<int>& nums) {
            memset(dp, -1, sizeof(dp));
            int n=nums.size();
            nums.insert(nums.begin(), 1);
            nums.push_back(1);
            return dfs(nums, 1, n);
        }
};
