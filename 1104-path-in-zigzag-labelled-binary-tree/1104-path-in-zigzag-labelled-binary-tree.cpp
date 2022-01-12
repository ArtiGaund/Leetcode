class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        deque<int> q;
        vector<int> par(1000002,-1);
        q.push_back(1);
        int f1=1,br=0,cur=2;
        while(!br)
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int x;
                if(f1) //even level
                {
                    x=q.back();
                    q.pop_back();
                    q.push_front(cur);
                    q.push_front(cur+1);
                }
                else
                {
                    x=q.front();
                    q.pop_front();
                    q.push_back(cur);
                    q.push_back(cur+1);
                }
                cur+=2;
                par[cur-2]=par[cur-1]=x;
                if(cur>label)
                {
                    br++;
                    break;
                }
            }
            f1=1-f1;
        }
        vector<int> res;
        while(label!=-1)
        {
            res.push_back(label);
            label=par[label];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};