
class UnionFind{
    public: vector<int> root;
            vector<int> rank;
            int count;
    UnionFind(int sz) : root(sz), rank(sz), count(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    bool merge(int a, int b){
        int x = find(a);
        int y = find(b);
        if(x==y) return false; //no merge done
        //rank[x] denotes the height of the tree with x as parent -- This is for making the tree stucture balanced --gives O(n*logn) complexity (similar to a balanced tree)
        if(rank[x]>rank[y]){
            root[y]= x;
        }
        else{
            root[x]=y;
            if(rank[x]==rank[y]) rank[y]++;
        }
        count--;
        return true;
    }
};
    class Solution {
public:
    
    bool validTree(int n, vector<vector<int>>& edges) {
        // condition 1: graph must contain n-1 edges
        if(edges.size()!=n-1) return false;
        //2: graph must contain single connectes component
        // create a new union set
         UnionFind uf(n);
        for(auto v:edges)
        {
            if(!uf.merge(v[0],v[1])) return false;
        }
        return true;
    }
};