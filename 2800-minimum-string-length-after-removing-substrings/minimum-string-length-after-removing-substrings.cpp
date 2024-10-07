class Solution {
public:
    int minLength(string s) {
        int res=0;
        vector<char> temp(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            temp[res]=temp[i];
            if(res>0 and (temp[res-1]=='A' or temp[res-1]=='C') and temp[res]==temp[res-1]+1){
                res--;
            }else res++;
        }
        return res;
    }
};