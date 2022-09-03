class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        queue<int> q;
        for(int i=1;i<10;i++)
            q.push(i);
        for(int i=1;i<N;i++)
        {
            int size=q.size();
            for(int j=0;j<size;j++)
            {
                int num=q.front();
                q.pop();
                int unit=num%10;
                if(unit+K<10)
                    q.push(num*10+unit+K);
                if(unit-K>=0&&K!=0)
                    q.push(num*10+unit-K);
            }
        }
        vector<int> ans;
        if(N==1)
            ans.push_back(0);
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};