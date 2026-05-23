class Solution {
public:

    int partition(vector<int>& nums, int left, int right) {
        int randIndex = left + rand() % (right - left + 1);
        swap(nums[left], nums[randIndex]);

        int pivot = nums[left];
        int start = left + 1;
        int end = right;

        while (start <= end) {

            while (start <= right && nums[start] > pivot)
                start++;

            while (end > left && nums[end] < pivot)
                end--;

            if (start > end) break;

            swap(nums[start], nums[end]);
            start++;
            end--;
        }

        swap(nums[left], nums[end]);
        return end;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int pivot = partition(nums, left, right);

            if (pivot == k - 1) return nums[pivot];
            else if (pivot > k - 1) right = pivot - 1;
            else left = pivot + 1;
        }

        return -1;
    }
};
