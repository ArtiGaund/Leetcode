class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReachableDis=0,maxNextAvailableDis=0,minStep=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            maxNextAvailableDis=max(maxNextAvailableDis,i+nums[i]);
            if(i==maxReachableDis)
            {
                minStep+=1;
                maxReachableDis=maxNextAvailableDis;
            }
        }
        return minStep;
    }
};