class Solution {
public:
int digit[100];
    bool isPalindrome(long long x, long long k){
        int length=-1;
        while(x){
            ++length;
            digit[length]=x%k;
            x/=k;
        }
        for(int i=0,j=length;i<j;i++,j--){
            if(digit[i]!=digit[j]) return false;
        }
        return true;
    }
    long long kMirror(int k, int n) {
        int left=1,count=0;
        long long res=0;
        while(count<n){
            int right=left*10;
            for(int op=0;op<2;op++){
                for(int i=left;i<right && count<n;i++){
                    long long combined=i;
                    int x=(op==0? i/10: i);
                    while(x){
                        combined = combined*10+x%10;
                        x/=10;
                    }
                    if(isPalindrome(combined, k)){
                        count++;
                        res+=combined;
                    }
                }
            }
            left=right;
        }
        return res;
    }
};