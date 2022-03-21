class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26);
        for(int i=0;i<s.size();i++)
            last[s[i]-'a']=i;
        int j=0,anchor=0;
        vector<int> res;
        for(int i=0;i<s.size();i++)
        {
            j=max(j,last[s[i]-'a']);
            if(i==j)
            {
                res.push_back(i-anchor+1);
                anchor=i+1;
            }
        }
        return res;
    }
};