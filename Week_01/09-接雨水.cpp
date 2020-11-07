class Solution{
    public:
        int trap(vector<int>& height){
            stack<int>stk;
            int ans=0;
            for(int i=0;i<height.size();i++){
                if(!stk.empty()&&height[i]>height[stk.top()]){
                    int cur=stk.top();
                    stk.pop();
                    if(stk.empty)break;
                    int l=stk.top();
                    int r=i;
                    int h=min(height[r], height[l])-height[cur];
                    ans+=(r-l+1)*h;
                }
                stk.push(i);
            }
            return ans;
        }
};
