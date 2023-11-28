class Solution {
public:
    int numberOfWays(string corridor) {
        int mod=1e9+7;
        int zero=0,one=0,two=1;
        for(char thing:corridor){
            if(thing=='S'){
                zero=one;
                swap(one,two);
            }else{
                two=(two+zero)%mod;
            }
        }
        return zero;
    }
};