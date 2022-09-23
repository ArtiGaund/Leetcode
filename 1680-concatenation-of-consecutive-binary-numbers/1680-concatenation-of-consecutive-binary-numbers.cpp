class Solution {
public:
    int concatenatedBinary(int n) {
        long long res=1;
        long long M=1e9+7;
        for(int i=2;i<=n;i++)
        {
            int pos=log(i)/log(2)+1;
            res=((res<<pos)%M+i)%M;
        }
        return res;
    }
};