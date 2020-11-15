class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>>mp;
        vector<vector<string>>ans;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string tmp=strs[i];
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(i);
        }
        for(auto m:mp){
            vector<int>vec=m.second;
            vector<string>str;
            for(int i=0,n=vec.size();i<n;i++){
                str.push_back(strs[vec[i]]);
            }
            ans.push_back(str);
        }
        return ans;
    }
};
