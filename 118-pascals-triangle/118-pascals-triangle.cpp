class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0) return res;
        res.push_back({1});
        if(numRows==1) return res;
        res.push_back({1,1});
        if(numRows==2) return res;
        int i=2;
         while(i<numRows)
        {
            vector<int> temp(i+1,0);
            temp[0]=1,temp[i]=1;
            for(int j=1;j<i;j++)
            {
                temp[j]=res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(temp);
            i++;
        }
        return res;
    }
};