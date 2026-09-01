class Solution {
public:
    void sortColors(vector<int>& nums) {
        int k=nums.size();
        for(int i=0 ; i<k-1; i++){
            int swapped = 0;
            for(int j=0; j<k-1-i; j++){
                if(nums.at(j)> nums.at(j+1)) {
                swap(nums.at(j),nums.at(j+1));
                swapped=1;
                }
            }
            if(swapped==0) break;
        }
    }
};