class Solution {
public:
    int countHomogenous(string s) {
        int res=0;
        int curStreak=0;
        int mod= 1e9+7;
        for(int i=0;i<s.size();i++){
            if(i==0 or s[i]==s[i-1]) curStreak++;
            else curStreak=1;
            res=(res+curStreak)%mod;
        }
        return res;
    }
};