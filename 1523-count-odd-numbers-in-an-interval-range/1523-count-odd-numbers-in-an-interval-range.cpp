class Solution {
public:
    int countOdds(int low, int high) {
        if((low&1)!=0 or (high&1)!=0)
            return 1+(high-low>>1);
        return (high-low)>>1;
    }
};