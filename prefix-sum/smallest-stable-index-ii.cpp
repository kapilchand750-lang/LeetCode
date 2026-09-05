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

        int instabilityScore;
        int i = 0;
        int j = 0;
        while(i < n){
            auto minIndex = min_element(nums.begin()+i, nums.end());
            int smallest = *minIndex;
            while(nums.begin()+i <= minIndex){
                int largest = prefMax[i];
                
                instabilityScore = largest - smallest;

                if(instabilityScore <= k)
                    return i;
                
                i++;
            }
        }

        return -1;
    }
};