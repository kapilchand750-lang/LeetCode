class Solution {
public:
    int countPrimes(int n) {
       
    vector<int> primeSieve(n, 1);

    for(int i = 2; i*i<n; i++){
        if(primeSieve[i]==1){
            for(int j = i*i; j<n; j += i){
                primeSieve[j] = 0;
            }
        }
    }

    int cnt = 0;
    for(int i = 2; i<n; i++){
        if(primeSieve[i]==1) cnt++;
    }

    return cnt;
    }
};