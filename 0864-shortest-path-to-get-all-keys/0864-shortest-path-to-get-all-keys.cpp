class State
{
    public:
    int i,j,keys;
    State(int i,int j,int keys)
    {
        this->i=i;
        this->j=j;
        this->keys=keys;
    }
};
class Solution {
public:
    bool boundary(int i,int j,int m,int n)
    {
        return (i<0 or i>=m or j<0 or j>=n);
    }
    int shortestPathAllKeys(vector<string>& grid) {
        int start_i = -1, start_j = -1, total_keys = 0, m = grid.size(), n = grid[0].size();
        set<string> visited;

        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                if(grid[i][j] == '@'){
                    start_i = i;
                    start_j = j;
                }
                else if(grid[i][j]>='a' && grid[i][j]<='z')
                total_keys++;
            }
        }

        State start = {start_i, start_j, 0};
        queue<State> q;
        vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int steps = 0;
        string s = to_string(start_i) + " " + to_string(start_j) + " " + to_string(0);
        q.push(start);
        visited.insert(s);

        while(!q.empty()){
            int size = q.size();

            while(size--){
                State curr = q.front();
                q.pop();

                if(curr.keys == (1<<total_keys) - 1)
                return steps;

                for(auto itr:directions){
                    int r = curr.i + itr[0];
                    int c = curr.j + itr[1];
                    int keys = curr.keys;

                    if(!boundary(r, c, m, n)){
                        char ch = grid[r][c];

                        if(ch == '#')
                        continue;

                        if(ch>='a' && ch<='f')
                        keys |= 1<<(ch-'a');

                        if(ch>='A' && ch<='F' && ((keys >> (ch - 'A')) & 1) == 0)
                        continue;

                        string temp = to_string(r) + " " + to_string(c) + " " + to_string(keys);

                        if(!visited.count(temp)){
                            visited.insert(temp);
                            State str(r, c, keys);
                            q.push(str);
                        }
                    }
                }
            }
        
            steps++;
        }

        return -1;
    }
};