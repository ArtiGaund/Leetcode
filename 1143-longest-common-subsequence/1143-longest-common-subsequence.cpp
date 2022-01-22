class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
       vector<int> r0(m+1,0),r1(m+1,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                    r0[j]=r1[j-1]+1;
                else
                    r0[j]=max(r1[j],r0[j-1]);
            }
            swap(r0,r1);
        }
        return r1[m];
    }
};