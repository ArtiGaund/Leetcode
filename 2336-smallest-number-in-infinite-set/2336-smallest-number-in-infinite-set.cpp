class SmallestInfiniteSet {
public:
    set<int> st;
    int curInteger;
    SmallestInfiniteSet() {
        curInteger=1;
    }
    
    int popSmallest() {
        int res;
        if(!st.empty())
        {
            res=*st.begin();
            st.erase(st.begin());
        }
        else
        {
            res=curInteger;
            curInteger+=1;
        }
        return res;
    }
    
    void addBack(int num) {
        if(curInteger<=num or st.find(num)!=st.end()) return;
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */