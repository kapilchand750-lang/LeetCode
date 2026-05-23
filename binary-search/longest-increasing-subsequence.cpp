class Solution {
private:
    int lowerBound(vector<int>& tails, int key){
        int start = 0;
        int n = tails.size();
        int end = n-1;
        int ans = n;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(tails[mid]>=key){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int>tails;
        tails.push_back(nums[0]);
        for(int i = 1; i<n; i++){
            if(nums[i]>tails.back()){
                tails.push_back(nums[i]);
            }
            else{
                int pos = lowerBound(tails, nums[i]);
                tails[pos] = nums[i];
            }
        }
        return tails.size();
    }
};