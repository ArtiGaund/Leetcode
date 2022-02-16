class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> partialSum(length+1,0);
        for(auto index:updates)
        {
            partialSum[index[0]]+=index[2];
            partialSum[index[1]+1]-=index[2];
        }
        for(int i=1;i<length;i++)
            partialSum[i]+=partialSum[i-1];
        partialSum.pop_back();
        return partialSum;
    }
};