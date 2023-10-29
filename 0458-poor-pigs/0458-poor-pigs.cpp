class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
         int time=minutesToTest/minutesToDie;
        int res=0;
        while(pow(time+1,res)<buckets)
        {
            res++;
        }
        return res;
    }
};