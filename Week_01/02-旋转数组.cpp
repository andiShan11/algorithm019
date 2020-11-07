class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i=0, counter=0, n=nums.size();
        k=k%n;
        for(int start=0;counter<n;start++){
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                counter++;
            } while (start != current);
        }
    }
};
