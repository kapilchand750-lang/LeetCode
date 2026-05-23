class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector <int> news;
        k = k % nums.size();
        int a=nums.size()-1;
        for(int i=a-k+1; i<a+1; i++){
            news.push_back(nums[i]);
        }

        for(int j=nums.size()-1-k; j>=0; j--){
            nums[j+k]=nums[j];
        }

        for(int i=0; i<k; i++){
            nums[i]=news[i];
        }
    }
};