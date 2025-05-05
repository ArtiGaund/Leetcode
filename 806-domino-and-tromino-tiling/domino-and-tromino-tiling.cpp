class Solution {
public:
    int numTilings(int n) {
         int mod=1'000'000'007;
        if(n<=2) return n;
        long fprev=1L,fcur=2L,pcur=1L;
        for(int k=3;k<n+1;k++)
        {
            long temp=fcur;
            fcur=(fcur+fprev+2*pcur)%mod;
            pcur=(pcur+fprev)%mod;
            fprev=temp;
        }
        return static_cast<int>(fcur);
    }
};