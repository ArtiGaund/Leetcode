class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> low; //max heap;
    priority_queue<int,vector<int>,greater<int>> high; //min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        low.push(num); //adding in max heap;
        high.push(low.top()); //balancing min heap and max heap
        low.pop();
        if(low.size()<high.size()) // mainintain size property
        {
            low.push(high.top());
            high.pop();
        }
        
    }
    
    double findMedian() {
        return (low.size()>high.size()?low.top(): ((double)(low.top()+high.top()))*0.5);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */