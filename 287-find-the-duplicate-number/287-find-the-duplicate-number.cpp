class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> count(n+1,0);
        for(int a:nums) count[a]++;
        for(int i=0;i<=n;i++)
            if(count[i]>1) return i;
        return -1;
    }
};