class Solution {
    long long revCnt = 0;

    void merge(vector<int>&arr, int start, int mid, int end){
        int n1 = mid - start + 1;
        int n2 = end - mid;

        vector<int>left(n1);
        vector<int>right(n2);
        
        for(int i = 0; i<n1; i++)
            left[i] = arr[start + i];
        
        for(int j = 0; j<n2; j++)
            right[j] = arr[mid + j + 1];

        int i = 0; 
        int j = 0;
        int k = start;

        while(i<n1 && j<n2){
            if(left[i]<=right[j])
                arr[k++] = left[i++];
            else
                arr[k++] = right[j++];
        }

        while(i<n1) arr[k++] = left[i++];

        while(j<n2) arr[k++] = right[j++];
    }

    void mergeSort(vector<int>&arr, int start, int end){
        if(start<end){
            int mid = start + (end - start)/2;
            mergeSort(arr, start, mid);
            mergeSort(arr, mid + 1, end);
            int j = mid + 1;
            for(int i = start; i<=mid; i++){
                while(j<=end && (long long)arr[i]>2LL*arr[j])
                j++;
                revCnt +=j - (mid + 1);
            }
            merge(arr, start, mid, end);
        }
    }

public:
    int reversePairs(vector<int>& nums) {
        vector<int>arr = nums;
        revCnt = 0;
        mergeSort(arr, 0, nums.size()-1);
        return revCnt;
    }
};