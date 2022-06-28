class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(char c:s) freq[c-'a']++;
        int deleteCount=0;
        unordered_set<int> seen;
        for(int i=0;i<26;i++)
        {
            while(freq[i] and seen.find(freq[i])!=seen.end())
            {
                freq[i]--;
                deleteCount++;
            }
            seen.insert(freq[i]);
        }
        return deleteCount;
    }
};