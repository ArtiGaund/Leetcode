class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        for(auto e:edges){
            indegree[e[1]]++;
        }
        int champ=-1,count=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                count++;
                champ=i;
            }
        }
        return count>1?-1:champ;
    }
};