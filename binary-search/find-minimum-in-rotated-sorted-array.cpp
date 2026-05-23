class Solution {
public:
    int findMin(vector<int> &nums)  {
      int start = 0, end = nums.size()-1;
      int min = INT_MAX;
      while(start<=end){
          int mid = start + (end - start)/2;
          if(nums[start]<=nums[mid]){
              if(nums[start]<min) min = nums[start];
              start= mid+1;
          }
          else{
              if(nums[mid]<=min) min = nums[mid];
              end = mid-1;
          }
      }
      return min;
    }
};