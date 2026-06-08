class Solution {
    bool solve(int n, int& k, string& temp, int mask){
        if(temp.size()==n){
            k--;
            return (k==0);
        }

        for(int i = 0; i<n; i++){
            if((mask&(1<<i))==0){
                temp.push_back((i+1)+'0');
                if(solve(n, k, temp, mask|(1<<i)))
                    return true;
                temp.pop_back();
            }
        }
        return false;
    }
public:
    string getPermutation(int n, int k) {
        string temp;
        solve(n, k, temp, 0);
        return temp;
    }
};