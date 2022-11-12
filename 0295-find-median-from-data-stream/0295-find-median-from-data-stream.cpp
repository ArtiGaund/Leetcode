#include<bits/stdc++.h>
class MedianFinder {
public:
    priority_queue<int> maxH;
    priority_queue<int,vector<int>,greater<int>> minH;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxH.push(num);                                    // Add to max heap

        minH.push(maxH.top());                               // balancing step
        maxH.pop();

        if (maxH.size() < minH.size()) {                     // maintain size property
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
         return maxH.size() > minH.size() ? maxH.top() : ((double) maxH.top() + minH.top()) * 0.5;
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */