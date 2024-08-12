// This is my initial bruteforce solution
// This problem can be solved using min heap which will be way more optimized

class KthLargest {
public:

    int k;
    vector<int> nums;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
        sort(this->nums.begin(), this->nums.end(), greater<int>());
    }
    
    int add(int val) {
        for(auto it = nums.begin(); it != nums.end(); it++){
            if(val > *it){
                nums.insert(it, val);
                return nums[k-1];
            }
        }

        nums.push_back(val);
        return nums[k-1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */