class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==0) return {};
        vector<vector<int>>ans;
        vector<bool>vis(nums.size(),false);
        vector<int>target(nums.size());
        dfs(ans,nums, 0,target,vis);
        return ans;
    }
    void dfs(vector<vector<int>>&ans, vector<int>& nums, int index, vector<int>target,vector<bool>vis){
        if(index==nums.size()) ans.push_back(target);
        else{
            for(int i=0;i<nums.size();i++){
                if(vis[i]) continue;
                vis[i]=true;
                target[index]=nums[i];
                dfs(ans, nums,index+1,target,vis);
                vis[i]=false;
            }
        }
    }
};
