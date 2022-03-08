class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<vector<char>> revpairs={{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
        queue<string> q;
        int curStrlen;
        if(n%2==0)
        {
            curStrlen=0;
            q.push("");
        }
        else
        {
            curStrlen=1;
            q.push("0");
            q.push("1");
            q.push("8");
        }
        while(curStrlen<n)
        {
            curStrlen+=2;
            for(int i=q.size();i>0;i--)
            {
                string num=q.front();
                q.pop();
                for(auto it:revpairs)
                {
                    if(curStrlen!=n or it[0]!='0')
                    {
                        q.push(it[0]+num+it[1]);
                    }
                }
            }
        }
        vector<string> res;
        while(!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};