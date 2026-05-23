class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = nums.size();
        int j=0;
        for(int i=0; i<k; i++){
            if(nums[i]!=0) {nums[j]=nums[i]; j=j+1;}
        }
        
        for(j;j<k;j++){
            nums[j]=0;
        }
    }
};