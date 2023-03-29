class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        int maxSat=0;
        int suffixSum=0;
        for(int i=sat.size()-1;i>=0 and suffixSum+sat[i]>0;i--)
        {
            suffixSum+=sat[i];
            maxSat+=suffixSum;
        }
        return maxSat;
    }
};