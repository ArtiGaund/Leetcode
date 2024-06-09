class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefixMod=0,res=0;
        vector<int> modGroups(k);
        modGroups[0]=1;
        for(int num:nums){
            prefixMod=(prefixMod+num%k+k)%k;
            res+=modGroups[prefixMod];
            modGroups[prefixMod]++;
        }
        return res;
    }
};