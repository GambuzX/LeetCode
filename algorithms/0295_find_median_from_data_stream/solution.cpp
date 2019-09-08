
class MedianFinder {

private:
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        lo = priority_queue<int>();
        hi = priority_queue<int, vector<int>, greater<int>>();
    }
    
    void addNum(int num) {
        
        lo.push(num);

        hi.push(lo.top());
        lo.pop();

        if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        return lo.size() == hi.size() ? (lo.top() + hi.top()) / 2.0 : lo.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */