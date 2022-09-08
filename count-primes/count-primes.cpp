class Solution {
public:
    int countPrimes(int n) {
         if(n==0||n==1)
            return 0;
        int prime[n+1];
        for(int i=2;i<n;i++)
            prime[i]=true;
        for(int i=2;i*i<n;i++)
        {
            if(prime[i]==true)
            {
                for(int j=i*i;j<n;j+=i)
                    prime[j]=false;
            }
        }
        int ans=0;
        for(int i=2;i<n;i++)
        {
            if(prime[i]==true)
                ans++;
        }
        return ans;
    }
};