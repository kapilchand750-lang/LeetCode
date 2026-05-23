class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector <int> record ;
        for(auto c = 0; c<operations.size(); c++){
            if(operations[c] == "C") record.pop_back();
            else if(operations[c] == "D") record.push_back(2*record[record.size()-1]);
            else if(operations[c] == "+") record.push_back(record[record.size()-1]+record[record.size()-2]);
            else record.push_back(stoi(operations[c]));
        }
        int total = 0;
        for (auto d : record) total += d;
        return total;
    }
};