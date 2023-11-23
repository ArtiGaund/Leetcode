class Solution {
public:
    bool check(vector<int> &temp){
        sort(temp.begin(),temp.end());
        int diff=temp[1]-temp[0];
        for(int i=2;i<temp.size();i++)
            if(temp[i]-temp[i-1]!=diff) return false;
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for(int i=0;i<l.size();i++){
            vector<int> temp(begin(nums)+l[i],begin(nums)+r[i]+1);
            res.push_back(check(temp));
        }
        return res;
    }
};