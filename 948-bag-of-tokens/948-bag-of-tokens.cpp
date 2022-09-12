class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int res=0;
        int i=0,j=n-1;
        int cur=0;
        while(i<=j&&P>=tokens[i])
        {
            while(i<=j&&P>=tokens[i])
            {
                P-=tokens[i];
                cur++;
                i++;
            }
            res=max(cur,res);
            while(j>=i&&cur&&P<tokens[i])
            {
                cur--;
                P+=tokens[j];
                j--;
            }
        }
        return res;
    }
};