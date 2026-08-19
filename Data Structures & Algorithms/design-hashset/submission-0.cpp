class MyHashSet {
private:
    vector<list<int>> v;
    int capacity;
    int hash(int n) {
        long long hash_code = n;
        // 67
        hash_code *= 67;
        // jefferson
        hash_code += 715;
        // folk valley
        hash_code *= 102;
        hash_code += 111;
        hash_code *= 108;
        hash_code += 107;
        // within bounds
        return hash_code % capacity;
    }
public:
    MyHashSet() {
        capacity = 256;
        v = vector<list<int>>(capacity);
    }
    
    void add(int key) {
        if(contains(key)) {
            return;
        }
        int hash_code = hash(key);
        auto& bucket = v[hash_code];
        bucket.push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)) {
            return;
        }
        int hash_code = hash(key);
        auto& bucket = v[hash_code];
        for(auto it = bucket.begin(); it != bucket.end(); it++) {
            if(*it == key) {
                bucket.erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int hash_code = hash(key);
        auto& bucket = v[hash_code];
        for(auto it = bucket.begin(); it != bucket.end(); it++) {
            if(*it == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */