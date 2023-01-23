class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> temp(n+1,0);
        for(auto p:trust)
        {
            temp[p[0]]--;
            temp[p[1]]++;
        }
        for(int i=1;i<=n;i++)
            if(temp[i]==n-1) return i;
        return -1;
    }
};