class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int biggest=0,secBiggest=0;
        for(int num:nums){
            if(num>biggest){
                secBiggest=biggest;
                biggest=num;
            }else{
                secBiggest=max(secBiggest,num);
            }
        }
        return (biggest-1)*(secBiggest-1);
    }
};