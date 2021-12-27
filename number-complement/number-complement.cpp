class Solution {
public:
    int findComplement(int num) {
         int t=num,pos=0;
        while(t)
        {
            num=num^(1<<pos);
            pos++;
            t=(t>>1);
        }
        return num;
    }
};