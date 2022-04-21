class MyHashSet {
public:
    vector<int> data;
    MyHashSet() {
       data=vector<int>(1000001,-1);
    }
    
    void add(int key) {
        if(data[key]==-1)
            data[key]=1;
    }
    
    void remove(int key) {
        data[key]=-1;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return data[key]==1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */