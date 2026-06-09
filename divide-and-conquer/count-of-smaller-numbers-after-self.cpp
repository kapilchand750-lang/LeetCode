class Solution {
    vector<int>cnt;

    void merge(vector<pair<int, int>>&arr, int start, int mid, int end){
        int n1 = mid - start + 1;
        int n2 = end - mid;

        vector<pair<int, int>>left(n1);

        for(int i = 0; i<n1; i++)
            left[i] = arr[i + start];

        vector<pair<int, int>>right(n2);

        for(int j = 0; j<n2; j++)
            right[j] = arr[j + mid + 1];

        int i = 0; int j = 0; int k = start;

        int rightSmallerCnt = 0;
        while(i<n1 && j<n2){
            if(left[i].first <= right[j].first){
                cnt[left[i].second] += rightSmallerCnt;
                arr[k++] = left[i++];
            }
            else {
                rightSmallerCnt++;
                arr[k++] = right[j++];
            }
        }

        while(i<n1){
            cnt[left[i].second] += rightSmallerCnt;
            arr[k++] = left[i++];
        }

        while(j<n2)
            arr[k++] = right[j++];
    }

    void mergeSort(vector<pair<int, int>>&arr, int start, int end){
        if(start<end){
            int mid = start + (end - start)/2;
            mergeSort(arr, start, mid);
            mergeSort(arr, mid + 1, end);
            merge(arr, start, mid, end);
        }
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        cnt.resize(n, 0);
        vector<pair<int, int>>arr;
        for(int i = 0; i<n; i++)
            arr.push_back({nums[i], i});
        mergeSort(arr, 0, n-1);
        return cnt;
    }
};