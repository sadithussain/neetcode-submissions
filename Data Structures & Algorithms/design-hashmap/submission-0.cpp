class MyHashMap {
private:
    struct Node {
        int key;
        int value;

        Node(int key, int value): key(key), value(value) {}
    };
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
    int capacity;
    vector<list<Node*>> v;
public:
    MyHashMap() {
        capacity = 256;
        v = vector<list<Node*>>(capacity);
    }
    
    void put(int key, int value) {
        int hash_code = hash(key);
        auto& bucket = v[hash_code];
        for(auto it = bucket.begin(); it != bucket.end(); it++) {
            if((*it) -> key == key) {
                (*it) -> value = value;
                return;
            }
        }
        bucket.push_back(new Node(key, value));
    }
    
    int get(int key) {
        int hash_code = hash(key);
        auto& bucket = v[hash_code];
        for(auto it = bucket.begin(); it != bucket.end(); it++) {
            if((*it) -> key == key) {
                return (*it) -> value;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int hash_code = hash(key);
        auto& bucket = v[hash_code];
        for(auto it = bucket.begin(); it != bucket.end(); it++) {
            if((*it) -> key == key) {
                delete (*it);
                bucket.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */