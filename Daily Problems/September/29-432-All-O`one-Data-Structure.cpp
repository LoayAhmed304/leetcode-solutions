class AllOne {
public:
    unordered_map<string, int> count;
    set<pair<int, string>> main; // Sorted

    AllOne() {
        count.clear();    
    }
    
    void inc(string key) {
        int c = count[key];
        count[key]++;
        main.erase({c, key});
        main.insert({c+1, key});
    }
    
    void dec(string key) {
        int c = count[key];
        count[key]--;
        main.erase({c, key});
        if(count[key] <= 0) count.erase(key);
        else
            main.insert({c-1, key});
    }
    
    string getMaxKey() {
        if(!main.empty()) return main.rbegin()->second;
        return "";
    }
    
    string getMinKey() {
        if(!main.empty()) return main.begin()->second;
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
