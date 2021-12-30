class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K%2==0||K%5==0)
            return -1;
        int r=0,n=1;
        for(int i=1;i<K+1;i++)
        {
            r=(r*10+1)%K;
            if(r==0)
                return i;
        }
        return n;
    }
};