class Solution {
public:
    void heapify(vector<int>& nums, int n, int parent){
        while(true){
            int largest = parent;
            int left  = 2*parent + 1;
            int right = 2*parent + 2;

            if(left < n && nums[left] > nums[largest])
                largest = left;

            if(right < n && nums[right] > nums[largest])
                largest = right;

            if(largest == parent) break;

            swap(nums[parent], nums[largest]);
            parent = largest;
        }
    }

    void buildMaxHeap(vector<int>& nums, int n){
        for(int i = (n/2)-1; i >= 0; i--)
            heapify(nums, n, i);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        buildMaxHeap(nums, n);

        for(int i = n-1; i > 0; i--){
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }

        return nums;
    }
};
