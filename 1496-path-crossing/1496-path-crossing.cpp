class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char,pair<int,int>> moves;
        moves['N']={0,1};
        moves['S']={0,-1};
        moves['W']={-1,0};
        moves['E']={1,0};
        unordered_set<string> vis;
        vis.insert("0,0");
        int x=0,y=0;
        for(char ch:path){
            pair<int,int> cur=moves[ch];
            int dx=cur.first;
            int dy=cur.second;
            x+=dx;
            y+=dy;
            string hash=to_string(x)+","+to_string(y);
            if(vis.find(hash)!=vis.end()) return true;
            vis.insert(hash);
        }
        return false;
    }
};