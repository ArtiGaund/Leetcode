class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evenDigitCount=0;
        for(int num:nums){
            if((num>=10 and num<=99) or (num>=1000 and num<=9999) or num== 100000) evenDigitCount++;
        }
        return evenDigitCount;
    }
};