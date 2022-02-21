class SnapshotArray {
public:
    vector<vector<pair<int,int>>> v;
    int snapIndex;
    SnapshotArray(int length) {
        v.resize(length);
        snapIndex=0;
    }
    
    void set(int index, int val) {
        if(v[index].empty() or v[index].back().first<snapIndex)
            v[index].push_back({snapIndex,val});
        else v[index].back().second=val;
    }
    
    int snap() {
        return snapIndex++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(v[index].begin(), v[index].end(), make_pair(snap_id, INT_MAX));
        if(it==v[index].begin()) return 0;
        else return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */