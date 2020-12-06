class Solution{
    public:
        int countSubstrings(string s){
            string ns="@#";
            for(auto str:s){ns+=str;ns+='#';}
            ns+='!';
            s=ns;
            int sz=s.size()-1, ans=0;
            vector<int>dp(sz,0);
            int idx=0,mx=0;
            for(int i=0;i<sz;i++){
                if(i<mx)dp[i]=min(dp[2*idx-i], mx-i);
                else dp[i]=1;
                while(s[i-dp[i]]==s[i+dp[i]]) dp[i]++;
                if(mx<i+dp[i]){
                    mx=i+dp[i];
                    idx=i;
                }
                ans+=(dp[i]/2);
            }
            return ans;
        }
};
