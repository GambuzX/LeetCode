class KthLargest {
private:
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> higher;
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) {   
        this->k = k;
        
        if (nums.empty()) return;
        
        for(int i : nums)
            lower.push(i);
        
        for(int i = 0; i < min(k, (int)nums.size()); i++) {
            higher.push(lower.top());
            lower.pop();
        }
    }
    
    int add(int val) {
        if (higher.size() < k) {
            higher.push(val);
        }        
        else if(val > higher.top()) {
            lower.push(higher.top());
            higher.pop();
            higher.push(val);
        }
        else {
            lower.push(val);
        }
        
        return higher.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */