class Solution {
public:
    vector<int> generateRow(int row)
    {
        long long res=1;
        vector<int> resRow;
        resRow.push_back(1);
        for(int col=1;col<row;col++)
        {
            res=res*(row-col);
            res=res/col;
            resRow.push_back(res);
        }
        return resRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=1;i<=numRows;i++)
        {
            vector<int> temp=generateRow(i);
            res.push_back(temp);
        }
        return res;
    }
};