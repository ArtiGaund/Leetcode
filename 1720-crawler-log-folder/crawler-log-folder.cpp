class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth=0;
        for(auto cur:logs){
            if(cur=="../"){
                depth=max(0,depth-1);
            }else if(cur!="./"){
                depth++;
            }
        }
        return depth;
    }
};