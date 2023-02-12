class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR=0;
        for(int a:nums) XOR=XOR^a;
        int rightmostSetBit=1;
        while((rightmostSetBit&XOR)==0)
            rightmostSetBit=rightmostSetBit<<1;
        int num1=0,num2=0;
        for(int num:nums)
        {
            if((num&rightmostSetBit)!=0) num1=num1^num;
            else num2=num2^num;
        }
        return {num1,num2};
    }
};