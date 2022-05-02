class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even,odd;
        for(int a:nums)
        {
            if(a%2==0) even.push_back(a);
            else odd.push_back(a);
        }
        nums.clear();
        for(int a:even) nums.push_back(a);
        for(int a:odd) nums.push_back(a);
        return nums;
    }
};