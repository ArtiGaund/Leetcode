class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int left=0,right=0;
        vector<int> freq(3,0);
        int total=0;
        while(right<n){
            char cur=s[right];
            freq[cur-'a']++;
            while(hasAllChars(freq)){
                total+=n-right;
                char leftChar=s[left];
                freq[leftChar-'a']--;
                left++;
            }
            right++;
        }
        return total;
    }
    bool hasAllChars(vector<int> &freq){
        return freq[0]>0 and freq[1]>0 and freq[2]>0;
    }
};