class Solution {
public:
    int maxConsecutiveAnswers(string ans, int k) {
        int maxSize=0;
        unordered_map<char,int> count;
        for(int right=0;right<ans.size();right++)
        {
            count[ans[right]]++;
            int minor=min(count['T'],count['F']);
            if(minor<=k) maxSize++;
            else count[ans[right-maxSize]]--;
        }
        return maxSize;
    }
};