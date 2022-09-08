class Solution {
public:
    int hammingDistance(int x, int y) {
        // perform the xor operation of x and y
        int temp = x ^ y; 
		
		// return the count of set-bits in temp
        int cnt = 0;          
        while(temp > 0) {
            cnt += temp & 1;
            temp = temp >> 1;
        }
        return cnt;
    }
};