class Solution {
public:
    vector<vector<string>> res;
    vector<string> cur;
    vector<vector<string>> partition(string s) {
        backtrack(0,s);
        return res;
    }
    void backtrack(int start,string &s)
    {
        if(start==s.size())
        {
            res.push_back(cur);
            return;
        }
        for(int i=start;i<s.size();i++)
        {
            if(ispalindrome(s,start,i))
            {
                cur.push_back(s.substr(start,i-start+1));
                backtrack(i+1,s);
                cur.pop_back();
            }
        }
    }
    bool ispalindrome(string s,int low,int high)
    {
        while(low<=high)
        {
            if(s[low]!=s[high]) return false;
            low++;
            high--;
        }
        return true;
    }
};