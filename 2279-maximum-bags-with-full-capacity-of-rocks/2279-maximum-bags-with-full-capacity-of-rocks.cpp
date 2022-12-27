class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        int fullBags=0;
        vector<int> remainCap(n);
        for(int i=0;i<n;i++)
            remainCap[i]=capacity[i]-rocks[i];
        sort(remainCap.begin(),remainCap.end());
        for(int i=0;i<n;i++)
        {
            if(additionalRocks>=remainCap[i])
            {
                additionalRocks-=remainCap[i];
                fullBags++;
            }
            else break;
        }
        return fullBags;
    }
};