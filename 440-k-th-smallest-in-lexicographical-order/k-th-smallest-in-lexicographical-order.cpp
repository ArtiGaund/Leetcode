class Solution {
public:
    int countSteps(int n,long prefix1,long prefix2){
        int steps=0;
        while(prefix1<=n){
            steps+=min((long)(n+1),prefix2)-prefix1;
            prefix1*=10;
            prefix2*=10;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        int cur=1;
        k--;
        while(k>0){
            int step=countSteps(n,cur,cur+1);
            if(step<=k){
                cur++;
                k-=step;
            }else{
                cur*=10;
                k--;
            }
        }
        return cur;
    }
};