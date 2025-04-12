class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> dict;
        int base=pow(10,(n-1)/2);
        int skip=n&1;
        for(int i=base;i<base*10;i++){
            string s=to_string(i);
            s+=string(s.rbegin()+skip,s.rend());
            long long palindromicInteger=stoll(s);
            if(palindromicInteger%k==0){
                sort(s.begin(),s.end());
                dict.emplace(s);
            }
        }
        vector<long long> factorial(n+1,1);
        long long res=0;
        for(int i=1;i<=n;i++){
            factorial[i]=factorial[i-1]*i;
        }
        for(const string &s:dict){
            vector<int> count(10);
            for(char ch:s){
                count[ch-'0']++;
            }
            long long tot=(n-count[0])*factorial[n-1];
            for(int x:count){
                tot/=factorial[x];
            }
            res+=tot;
        }
        return res;
    }
};