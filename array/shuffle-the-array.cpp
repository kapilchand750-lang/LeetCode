class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        if (n==1) return nums;
        vector<int>res;
        for(int i = 0; i<2*n; i++) res.push_back(nums[i]);
        for(int i = 0; i<2*n; i++){
            if(i%2==0) nums[i]=res[i/2];
            else 
            nums[i] = res[n+i/2];
        }
        return nums;
    }
};