class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0) return {1};
        vector<int> up=getRow(rowIndex-1);
        vector<int> res;
        res.push_back(1);
        for(int i=1;i<rowIndex;i++)
        {
            res.push_back(up[i-1]+up[i]);
        }
        res.push_back(1);
        return res;
    }
};