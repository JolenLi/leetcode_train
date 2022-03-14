class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;

    }

    vector<int> reset() {
        return this->nums;
    }

    vector<int> shuffle() {
        vector<int> res = this->nums;
        for(int i =1;i<res.size();i++){
            swap(res[i],res[i-rand()%(i+1)]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */