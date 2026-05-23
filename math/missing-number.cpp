class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0;
        int k = nums.size();
        int asum = 0;
        for(int i=1; i<=k; i++){
            total = total+i; 
        }
        for(int j=0; j<k; j++){
            asum = asum + nums[j];
        }
        return total - asum;
    }
};