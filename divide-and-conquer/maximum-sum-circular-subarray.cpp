class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int large = nums[0];
        int small = nums[0];
        int n = nums.size();
        int p1 = nums[0];
        int p2 = nums[0];
        int total = nums[0];
        for(int i = 1; i<n; i++){
            p1 = max(nums[i], nums[i]+p1);
            p2 = min(nums[i], nums[i]+p2);
            large = max(large, p1);
            small = min(small, p2);
            total += nums[i];
        }
        int circular = total-small;
        if(large>0)
            return max(large, circular);

        return large;
    }
};