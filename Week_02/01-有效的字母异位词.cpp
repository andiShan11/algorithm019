class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>alph;
        for(auto c:t)alph[c]++;
        for(auto c:s)if(--alph[c]<0)return false;
        for(auto a:alph)if(a.second>0) return false;
        return true;
    }
};
