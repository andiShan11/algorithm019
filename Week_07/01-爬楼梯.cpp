class Solution{
    public:
        int climbStairs(int n){
            vector<int>dp(n+1, -1);
            return dfs(n, dp);
        }
        int dfs(int n, vector<int>&dp){
            if(n<3)return n;
            if(dp[n]!=-1) return dp[n];
            return dp[n]=climbStairs(n-1)+climbStairs(n-2);
        }
};
