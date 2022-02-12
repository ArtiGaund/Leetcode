class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxH; //max heap;
    priority_queue<int,vector<int>,greater<int>> minH; //min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxH.push(num);
        minH.push(maxH.top());
        maxH.pop();
        if(maxH.size()<minH.size())
        {
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        if((minH.size()+maxH.size())%2==0) return((double) minH.top() + maxH.top()) * 0.5;
        else return maxH.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */