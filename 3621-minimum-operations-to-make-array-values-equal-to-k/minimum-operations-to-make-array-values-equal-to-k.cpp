class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int a:nums){
            if(a<k) return -1;
            else if(a>k) st.insert(a);
        }
        return st.size();
    }
};