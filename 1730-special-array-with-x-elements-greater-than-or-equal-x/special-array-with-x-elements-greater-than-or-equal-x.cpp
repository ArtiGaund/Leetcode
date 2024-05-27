class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq(n+1,0);
        for(int i=0;i<n;i++)
            freq[min(n,nums[i])]++;
        int val=0;
        for(int i=n;i>=1;i--){
            val+=freq[i];
            if(i==val) return i;
        }
        return -1;
    }
};