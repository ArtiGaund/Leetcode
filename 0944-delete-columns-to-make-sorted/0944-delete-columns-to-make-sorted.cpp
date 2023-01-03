class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs[0].size();
        int res=0;
        for(int col=0;col<n;col++)
        {
            for(int row=1;row<strs.size();row++)
            {
                if(strs[row][col]<strs[row-1][col])
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};