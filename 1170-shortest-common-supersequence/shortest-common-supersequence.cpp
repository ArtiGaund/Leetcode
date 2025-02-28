class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int s1Len=str1.size();
        int s2Len=str2.size();
        vector<vector<int>> dp(s1Len+1,vector<int>(s2Len+1,0));
        for(int r=0;r<=s1Len;r++)
        dp[r][0]=r;
        for(int c=0;c<=s2Len;c++) dp[0][c]=c;
        for(int r=1;r<=s1Len;r++){
            for(int c=1;c<=s2Len;c++){
                if(str1[r-1]==str2[c-1]){
                    dp[r][c]=dp[r-1][c-1]+1;
                }else{
                    dp[r][c]=min(dp[r-1][c],dp[r][c-1])+1;
                }
            }
        }
        string superSeq="";
        int r=s1Len,c=s2Len;
        while(r>0 and c>0){
            if(str1[r-1]==str2[c-1]){
                superSeq+=str1[r-1];
                r--;
                c--;
            }else if(dp[r-1][c]<dp[r][c-1]){
                superSeq+=str1[r-1];
                r--;
            }else{
                superSeq+=str2[c-1];
                c--;
            }
        }
        while(r>0){
            superSeq+=str1[r-1];
            r--;
        }
        while(c>0){
            superSeq+=str2[c-1];
            c--;
        }
        reverse(superSeq.begin(),superSeq.end());
        return superSeq;
    }
};