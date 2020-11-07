class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans;
        int flag=0,n=digits.size();
        ans.push_back((digits[n-1]+1)%10);
        flag=(digits[n-1]+1)/10;
        for(int i=n-2;i>=0;i--){
            ans.push_back((digits[i]+flag)%10);
            flag=(digits[i]+flag)/10;
        }
        if(flag) ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
