class Solution {
public:
    bool canJump(vector<int>&nums){
        int MAXX=0;
        for(int i=0;i<nums.size()&&MAXX<nums.size();i++){
            if(i>MAXX) return false;
            MAXX=max(MAXX,i+nums[i]);
        }
        return true;
    }
};
