class Solution {
public:
bool isPrime(int num){
    if(num<2) return false;
    if(num==2 or num==3) return true;
    if(num%2==0) return false;
    for(int divisor=3;divisor*divisor<=num;divisor+=2){
        if(num%divisor==0) return false;
    }
    return true;
}
    vector<int> closestPrimes(int left, int right) {
        int prevPrime=-1,closeA=-1,closeB=-1;
        int minDiff=1e6;
        for(int cand=left;cand<=right;cand++){
            if(isPrime(cand)){
                if(prevPrime!=-1){
                    int diff=cand-prevPrime;
                    if(diff<minDiff){
                        minDiff=diff;
                        closeA=prevPrime;
                        closeB=cand;
                    }
                    if(diff==2 or diff==1){
                        return {prevPrime,cand};
                    }
                    
                }
                prevPrime=cand;
            }
        }
        return (closeA==-1? vector<int>{-1,-1}: vector<int>{closeA,closeB});
    }
};