class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<int> r0(m+1),r1(m+1);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(text1[i]==text2[j])
                    r0[j]=r1[j+1]+1;
                else
                    r0[j]=max(r1[j],r0[j+1]);
            }
            swap(r0,r1);
        }
        return r1[0];
    }
};