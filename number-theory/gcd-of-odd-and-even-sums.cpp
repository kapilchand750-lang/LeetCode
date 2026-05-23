class Solution {
public:
    int gcdOfOddEvenSums(int n){
        int odd = 0;
        int even = 0;
        for(int i=0; i<n; i++){
            odd = odd + 2*i+1;
            even = even + 2*i +2;
        }
        while (odd != 0){
            int temp = odd;
            odd = even % odd;
            even = temp;
        }
    return even;
    }
};