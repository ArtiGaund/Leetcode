class Solution {
public:
    int bitwiseComplement(int n) {
        return ((2 << int(log2(max(n, 1)))) - 1) - n;
    }
};