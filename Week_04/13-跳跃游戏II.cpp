class Solution{
    public:
        int jump(vector<int>nums){
            if(nums.size()==0||nums.size()==1) return 0;
            
            int ans=0,tmp=0,maxx=0;
            for(int i=0;i<nums.size();i++){
                maxx=max(maxx, i+nums[i]);
                if(i==tmp){
                    if(maxx>=nums.size()-1) return ++ans;
                    tmp=maxx;
                    ans++;
                }    
            }
            return ans;
        }
};
