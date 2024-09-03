class Solution {
public:
    int getLucky(string s, int k) {
        int curNum=0;
        for(char ch:s){
            int pos=ch-'a'+1;
            while(pos>0){
                curNum+=pos%10;
                pos/=10;
            }
        }
        for(int i=1;i<k;i++){
            int digitSum=0;
            while(curNum>0){
                digitSum+=curNum%10;
                curNum/=10;
            }
            curNum=digitSum;
        }
        return curNum;
    }
};