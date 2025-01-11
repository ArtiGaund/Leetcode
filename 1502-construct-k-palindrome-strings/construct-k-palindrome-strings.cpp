class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        if(s.size()==k) return true;
        vector<int> freq(26);
        int oddCount=0;
        for(char ch:s) freq[ch-'a']++;
        for(int i=0;i<26;i++){
            if(freq[i]%2==1) oddCount++;
        }
        return oddCount<=k;
    }
};