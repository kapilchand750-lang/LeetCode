class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefMax(n);
        prefMax[0] = nums[0];
        for(int i = 1; i<n; i++){
            if(nums[i] > prefMax[i-1])
                prefMax[i] = nums[i];
            else 
            prefMax[i] = prefMax[i-1];
        }

        vector<int> suffMin(n);
        suffMin = nums;
        for(int i = n-2; i>=0; i--){
            if(nums[i] < suffMin[i+1])
                suffMin[i] = nums[i];
            else suffMin[i] = suffMin[i+1];
        }

        int instabilityScore;
        int i = 0;
        while(i < n){
            int largest = prefMax[i];
            int smallest = suffMin[i];

            instabilityScore = largest - smallest;

            if(instabilityScore <= k)
                return i;
                
            i++;
        }

        return -1;
    }
};