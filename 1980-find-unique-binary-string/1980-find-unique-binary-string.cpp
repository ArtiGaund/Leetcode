class Solution {
public:
    int n;
    unordered_set<string> set;
    string generate(string cur){
        if(cur.size()==n){
            if(set.find(cur)==set.end()) return cur;
            return "";
        }
        string addZero=generate(cur+'0');
        if(addZero.size()>0) return addZero;
        return generate(cur+'1');
    }
    string findDifferentBinaryString(vector<string>& nums) {
        n=nums.size();
        for(string num:nums) set.insert(num);
        return generate("");
    }
};