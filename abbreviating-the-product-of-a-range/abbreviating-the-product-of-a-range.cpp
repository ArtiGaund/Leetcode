class Solution {
public:
    string abbreviateProduct(int left, int right) {
        long long suff=1,c=0,max_suf=1000000000000;
        double pref=1.0;
        for(int i=left;i<=right;i++)
        {
            pref*=i;
            while(pref>=100000)
                pref/=10;
            suff*=i;
            while(suff%10==0)
            {
                suff/=10;
                ++c;
            }
            suff%=max_suf;
        }
        auto res=to_string(suff);
        return (res.size()<=10?res:to_string((int)pref)+"..."+res.substr(res.size()-5))+"e"+to_string(c);
    }
};