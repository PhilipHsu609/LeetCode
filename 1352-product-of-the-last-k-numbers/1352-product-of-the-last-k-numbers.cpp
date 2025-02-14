class ProductOfNumbers {
public:
    ProductOfNumbers() {
        pprod.push_back(1);
    }
    
    void add(int num) {
        if(num == 0) {
            pprod.clear();
            pprod.push_back(1);
        } else {
            pprod.push_back(pprod.back() * num);
        }
    }
    
    int getProduct(int k) {
        int idx = static_cast<int>(pprod.size() - 1) - k;
        if(idx < 0) {
            return 0;
        }
        return pprod.back() / pprod[idx];
    }

    vector<long long> pprod;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */