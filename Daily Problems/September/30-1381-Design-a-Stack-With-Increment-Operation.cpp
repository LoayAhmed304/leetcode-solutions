class CustomStack {
public:
    vector<int>vec;

    int size;
    int maxSize;

    CustomStack(int maxSize){
        vec.resize(maxSize);
        size = 0;
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(size >= maxSize) return;
        vec[size++] = x;
        
    }
    
    int pop() {
        if(size <= 0) return -1;

        return vec[--size];
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < k; i++){
            if(i >= size) break;
            vec[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
