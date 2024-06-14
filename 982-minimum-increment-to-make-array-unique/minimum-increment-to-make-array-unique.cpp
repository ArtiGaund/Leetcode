class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int max_val=0;
        for(int a:nums){
            max_val=max(max_val,a);
        }
        int n=nums.size();
        vector<int> count(n+max_val+1,0);
        for(int a:nums){
            count[a]++;
        }
        int res=0;
        for(int i=0;i<count.size();i++){
            if(count[i]<=1) continue;
            int duplicates = count[i]-1;
            count[i+1]+=duplicates;
            count[i]=1;
            res+=duplicates;
        }
        return res;
    }
};