class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        unordered_set<string> seen;
        q.push(start);
        seen.insert(start);
        int steps=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                string node=q.front();
                q.pop();
                if(node==end) return steps;
                for(char c:"ACGT")
                {
                    for(int j=0;j<node.size();j++)
                    {
                        string neighbor=node;
                        neighbor[j]=c;
                        if(!seen.count(neighbor) and find(bank.begin(),bank.end(),neighbor)!=bank.end())
                        {
                            q.push(neighbor);
                            seen.insert(neighbor);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
        
    }
};