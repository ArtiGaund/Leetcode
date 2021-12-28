class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0) return false;
        set<int> s;
        for(int n:nums)
        {
            if(s.count(n)) return true;
            s.insert(n);
        }
        return false;
    }
};