class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size();
        vector<bool> resolved(n-1,false);
        int unresolved=n-1,deletions=0;
        for(int j=0;j<m and unresolved>0;j++){
            bool bad=false;
            for(int i=0;i<n-1;i++){
                if(!resolved[i] and strs[i][j]>strs[i+1][j]){
                    bad=true;
                    break;
                }
            }
            if(bad){
                deletions++;
                continue;
            }
            for(int i=0;i<n-1;i++){
                if(!resolved[i] and strs[i][j]<strs[i+1][j]){
                    resolved[i]=true;
                    unresolved--;
                }
            }
        }
        return deletions;
    }
};