class Solution {
    vector<string>ans;

    void solve(string&num, int target, int idx, long long val, long long prev, string exp){
        if(idx==num.size()){
            if(val==target)
                ans.push_back(exp);
            return;
        }

        long long curr = 0;

        for(int i = idx; i<num.size(); i++){
            if(i>idx && num[idx]=='0') // to remove the formation of leading zero number
                break; 

            curr = curr * 10 + (num[i] - '0');

            string part = num.substr(idx, i - idx + 1);

            if(idx==0){
                solve(num, target, i + 1, curr, curr, part);
            }
            else{
                solve(num, target, i + 1, val + curr, curr, exp + "+" + part);
                solve(num, target, i + 1, val - curr, -curr, exp + "-" + part);
                solve(num, target, i + 1, val - prev + prev * curr, prev * curr, exp + "*" + part);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        string exp;
        solve(num, target, 0, 0, 0, exp);
        return ans;
    }
};