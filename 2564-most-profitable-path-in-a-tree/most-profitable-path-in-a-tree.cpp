class Solution {
public:
vector<vector<int>> graph;
vector<int> disFromBob;
int n;
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
      n=amount.size();
      graph.resize(n,vector<int>());
      for(auto e:edges){
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
      }  
      disFromBob.resize(n);
      return findPaths(0,0,0,bob,amount);
    }
    int findPaths(int source,int parent,int time,int bob,vector<int> &amount){
        int maxIncome=0,maxChild=INT_MIN;
        if(source==bob) disFromBob[source]=0;
        else disFromBob[source]=n;
        for(int adj:graph[source]){
            if(adj!=parent){
                maxChild=max(maxChild,findPaths(adj,source,time+1,bob,amount));
                disFromBob[source]=min(disFromBob[source],disFromBob[adj]+1);
            }
        }
        if(disFromBob[source]>time) maxIncome+=amount[source];
        else if(disFromBob[source]==time) maxIncome+=amount[source]/2;
        if(maxChild==INT_MIN) return maxIncome;
        return maxIncome+maxChild;
    }
};