class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> res;
        int len=s.size();
        int row=startPos[0];
        int col=startPos[1];
        int curRow=row;
        int curCol=col;
        
        for(int i=0;i<len;i++)
        {
            curRow=row;
            curCol=col;
            int count=0;
            for(int j=i;j<len;j++)
            {
                if(s[j]=='R') curCol++;
                else if(s[j]=='L') curCol--;
                else if(s[j]=='U') curRow--;
                else curRow++;
                if(isValid(curRow,curCol,n)) count++;
                else break;
            }
            res.push_back(count);
        }
        return res;
    }
    bool isValid(int row,int col,int n)
    {
        return (row>=0 and row<n and col>=0 and col<n);
    }
};