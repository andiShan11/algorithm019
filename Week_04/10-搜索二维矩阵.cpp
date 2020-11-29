class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(m==0) return false;
        int n=matrix[0].size();
        int l=0,r=m*n-1,mid,midValue;
        while(l<=r){
            mid=(l+r)/2;
            midValue=matrix[mid/n][mid%n];
            if(midValue==target){
                return true;
            }
            else if(midValue>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return false;
    }
};
