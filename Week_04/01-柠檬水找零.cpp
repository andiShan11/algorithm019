class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int>nums(3, 0);
        int n=bills.size();
        for(int i=0;i<n;i++){
            switch(bills[i]){
                case 5:
                    nums[0]++;
                    break;
                case 10:
                    if(nums[0]<=0) return false;
                    nums[0]--;
                    nums[1]++;
                    break;
                case 20:
                    if(nums[1]>0){
                        if(nums[0]<=0) return false;
                        nums[0]--;
                        nums[1]--;
                    }
                    else{
                        if(nums[0]<3)return false;
                        nums[0]-=3;
                    }
                    nums[2]++;
            }
        }
        return true;
    }
};
