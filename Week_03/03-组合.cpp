class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k) {
        if(cur==n+2) return;
        if (t.size() == k) {
            ans.push_back(t);
            return;
        }
        if(t.size()<k){
            t.push_back(cur);
            dfs(cur + 1, n, k);
        }
        t.pop_back();
        dfs(cur + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};
