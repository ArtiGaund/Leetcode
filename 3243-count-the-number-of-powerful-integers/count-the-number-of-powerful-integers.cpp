class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string begin=to_string(start-1),end=to_string(finish);
        return calculate(end,s,limit)-calculate(begin,s,limit);
    }
    long long calculate(string x,string s,int limit){
        if(x.size()<s.size()) return 0;
        if(x.size()==s.size()) return x>=s?1:0;
        string suffix=x.substr(x.size()-s.size(),s.size());
        long long count=0;
        int preLen=x.size()-s.size();
        for(int i=0;i<preLen;i++){
            if(limit<(x[i]-'0')){
                count+=(long)pow(limit+1,preLen-i);
                return count;
            }
            count+=(long)(x[i]-'0')*(long)pow(limit+1,preLen-1-i);
        }
        if(suffix>=s) count++;
        return count;
    }
};