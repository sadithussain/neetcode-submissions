class FreqStack {
private:
    // store the frequencies numbers
    unordered_map<int, int> freq;
    // map frequencies with their stacks
    unordered_map<int, stack<int>> m;
    // keep track of maximum frequency
    int max_freq;
public:
    FreqStack() {
        // initialize maximum frequency to 0
        max_freq = 0;
    }
    
    void push(int val) {
        // increment frequency
        freq[val]++;
        // push to correct stack
        m[freq[val]].push(val);
        // update maximum frequency if needed
        max_freq = max(max_freq, freq[val]);
    }
    
    int pop() {
        // get top number
        int val = m[max_freq].top();
        // pop it
        m[max_freq].pop();
        // decrease frequency
        freq[val]--;
        while(max_freq >= 0) {
            if(!m[max_freq].empty()) {
                break;
            }
            max_freq--;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */