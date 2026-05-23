class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for(auto i : nums){totalSum += i;}
        int leftSum=0;
        int rightSum=0;
        for(auto i=0; i<nums.size(); i++){
            rightSum= totalSum -(nums[i] + leftSum);
            if(leftSum == rightSum){
                return i;
            }
            leftSum += nums[i]; 
        }
        return -1;
    }
};