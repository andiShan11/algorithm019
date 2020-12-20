class Solution{
    public:
        vector<string> generateParenthesis(int n){
            if(n==0) return {};
            vector<string>ans;
            dfs(ans, "", n,0);
            return ans;
        }
        // 这个地方的 ans必须是值引用
        void dfs(vector<string>&ans, string target, int open, int close){
            if(open==0&&close==0) ans.push_back(target);
            else{
                if(open>0) dfs(ans, target+'(', open-1, close+1);
                if(close>0) dfs(ans, target+')', open, close-1);
            }
        }
};
