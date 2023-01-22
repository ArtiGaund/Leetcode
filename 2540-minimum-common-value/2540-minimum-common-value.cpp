class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        for(int a:nums1) st.insert(a);
        for(int a:nums2)
        {
            if(st.find(a)!=st.end())
                return a;
        }
        return -1;
    }
};