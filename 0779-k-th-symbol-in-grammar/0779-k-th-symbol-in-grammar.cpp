class Solution {
public:
    int dfs(int n,int k,int rootVal){
        if(n==1) return rootVal;
        int totalNodes=pow(2,n-1);
        // target node is present in right half sub tree of the cur root node
        if(k>(totalNodes/2)){
            int nextRootVal = (rootVal==0?1:0);
            return dfs(n-1,k-(totalNodes/2),nextRootVal);
        }
        else{ //left half
            int nextRootVal = (rootVal==0?0:1);
            return dfs(n-1,k,nextRootVal);
        }
    }
    int kthGrammar(int n, int k) {
        return dfs(n,k,0);
    }
};