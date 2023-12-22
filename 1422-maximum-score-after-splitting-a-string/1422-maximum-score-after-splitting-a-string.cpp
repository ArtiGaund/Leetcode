class Solution {
public:
    int maxScore(string s) {
        int ones=count(s.begin(),s.end(),'1');
        int res=0;
        int zeros=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='1'){
                ones--;
            }else{
                zeros++;
            }
            res=max(res,zeros+ones);
        }
        return res;
    }
};