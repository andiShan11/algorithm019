class Solution{
    public:
        int numDecodings(string s){
            int n=s.size();
            if(n==0) return 0;
            int pre = 1, curr = 1;
            vector<int>dp(n+1, 1);
            if(s[0]=='0') return 0;
            for(int i=1;i<n;i++){
                int tmp=curr;
                if(s[i]=='0'){
                    if(s[i-1]!='1'&&s[i-1]!='2') return 0;
                    else curr=pre;
                }
                else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')){
                    curr = curr+pre;
                }
                pre = tmp;
            }
            return curr;
        }
};
