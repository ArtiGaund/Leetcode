class Solution {
public:
    vector<vector<string>> res;
    vector<string> cur;
    vector<vector<string>> partition(string s) {
        backtrack(s,0);
        return res;
    }
    void backtrack(string s,int index)
    {
        if(index==s.size())
        {
            res.push_back(cur);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(isPalindrome(s,index,i))
            {
                cur.push_back(s.substr(index,i-index+1));
                backtrack(s,i+1);
                cur.pop_back();
            }
        }
    }
    bool isPalindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};