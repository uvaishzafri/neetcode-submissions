class LRUCache {
public:
    unordered_map<int, int> m; // key->value, m[key] ->value
    list<int> dll;             // keys list
    int cap;                   // capacity 
    
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    
    void moveToFirst(int key){  // to move keys to front
        // 1 2 3    -> initial list
        // Input- 3 -> operation to be done on Key 3
        // 1 2      -> erase 3
        // 3 1 2    -> push 3 in front of list
        dll.erase(find(dll.begin(),dll.end(),key));  // find key iterator and remove key
        dll.push_front(key);  // push key in front of list
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1; // if key isn't present return -1
        moveToFirst(key); // else push key in front
        return m[key];    // return value
    }
    
    void put(int key, int value) {
        if(m.count(key)){  // if key is already present
            m[key]=value;          // update key's value
            moveToFirst(key);      // move key to front
        }
        else{                      // if key isn't present
            dll.push_front(key);   // push key to front
            m[key]=value;          // set key->value pair
            cap--;                 // capacity reduced
        }
        
        if(cap<0){                 // If capacity becomes lesser than 0
            m.erase(dll.back());  // erase last key of dll from unordered_map
            dll.pop_back();        // pop last element from list
            cap++;                 // capacity increased
        }
        
    }
};
