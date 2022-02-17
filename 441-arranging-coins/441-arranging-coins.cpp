class Solution {
public:
    int arrangeCoins(int n) {
        long low=0,high=n;
        while(low<=high)
        {
            long k=low+(high-low)/2;
            long cur=k*(k+1)/2;
            if(cur==n) return (int)k;
            else if(n<cur) high=k-1;
            else low=k+1;
        }
        return (int)high;
    }
};