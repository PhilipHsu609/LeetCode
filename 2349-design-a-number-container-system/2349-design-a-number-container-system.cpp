class NumberContainers {
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(idx_map.find(index) != idx_map.end()) {
            num_map[idx_map[index]].erase(index);
        }
        num_map[number].insert(index);
        idx_map[index] = number;
    }
    
    int find(int number) {
        if(num_map[number].empty()) {
            return -1;
        }
        return *num_map[number].begin();
    }

    unordered_map<int, set<int>> num_map;
    unordered_map<int, int> idx_map;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */