class Solution {
public:
    int getSum(int a, int b) {
        unsigned int ua=(unsigned int)a;
        unsigned int ub=(unsigned int)b;
        while(ub)
        {
            uint64_t carry=ua&ub; //generate carry
            ua=ua^ub; //add value without generating carry
            ub=carry<<1;
        }
        return (int)ua;
    }
};