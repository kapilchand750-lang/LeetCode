class Solution {
public:
int lowerBound(vector<int> &nums, int target){
        int start = 0, end = nums.size()-1;
        int index = nums.size();
        while(start<=end){
            int mid = start + (end - start)/2;
            if(nums[mid]>=target){
                index = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return index;
    }
    
    int upperBound(vector<int> &nums, int target){
        int start = 0, end = nums.size()-1;
        int index = nums.size();
        while(start<=end){
            int mid = start + (end - start)/2;
            if(nums[mid]>target){
                index = mid;
                end = mid - 1;
            }
            else start = mid + 1; 
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums, target);
        if (lb==nums.size() || nums[lb]!=target) return {-1,-1};
        return {lb, upperBound(nums,target)-1};
    }
};