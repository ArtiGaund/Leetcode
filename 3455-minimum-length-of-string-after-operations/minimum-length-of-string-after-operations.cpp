class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        int total=0;
        for(int a:freq){
            if(a==0) continue;
            if(a%2==0) total+=2;
            else total+=1;
        }
        return total;
    }
};