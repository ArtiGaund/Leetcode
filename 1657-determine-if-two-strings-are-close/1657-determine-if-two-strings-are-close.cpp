class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        if(n!=m)
            return false;
        set<char> st1,st2;
        vector<int> freq1(26,0),freq2(26,0);
        for(int i=0;i<n;i++)
        {
            st1.insert(word1[i]);
            st2.insert(word2[i]);
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        if(st1==st2 and freq1==freq2) return true;
        return false;
    }
};