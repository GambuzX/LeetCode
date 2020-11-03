struct LListNode {
    LListNode *prev, *next;
    int key, val;
    LListNode(int k, int v) {
        this->key = k;
        this->val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    LListNode *head, *tail;
    unordered_map<int, LListNode> nodes;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
        nodes.clear();
    }
    
    void placeAtHead(LListNode& node) {
        if(node.key == head->key) return;
        
        // connect neighbours
        if(node.next != nullptr)
            node.next->prev = node.prev;
        if(node.prev != nullptr)
            node.prev->next = node.next;
        
        // update tail
        if(node.key == tail->key)
            tail = node.prev;
        
        // update head
        node.next = head;
        node.prev = nullptr;
        head->prev = &node;
        head = &node;
    }
    
    int get(int key) {
        unordered_map<int, LListNode>::iterator it = nodes.find(key);
        if (it == nodes.end()) return -1;
        
        placeAtHead(it->second);
        return it->second.val;
    }
    
    void put(int key, int value) {
        unordered_map<int, LListNode>::iterator it = nodes.find(key);
        if(it == nodes.end()) { // new key
            
            nodes.insert(make_pair(key, LListNode(key, value)));
            it = nodes.find(key);
            
            LListNode& curr = it->second;
            curr.next = head;
            if(head != nullptr) head->prev = &curr;
            head = &curr;
            if(tail == nullptr) tail = &curr;
            
            if(nodes.size() > capacity) { // remove last if full
                int tailKey = tail->key;
                tail = tail->prev;
                if(tail != nullptr) tail->next = nullptr;
                nodes.erase(nodes.find(tailKey));
            }
        }
        else {
            it->second.val = value;
            placeAtHead(it->second);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */