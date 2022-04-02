//
// Created by Jolen on 2022/4/1.
//

int missingNumber(vector<int> &nums) {
    int size = sizeof(int) * 8;
    int ans = 0;
    vector<int> bitmap((nums.size() / size + 1), 0);
    for (int &num:nums)
        bitmap[num / size] |= 1 << (num % size);
    for (int i = 0; i < nums.size() / size + 1; i++) {
        for (int j = 0; j < size; j++) {
            if ((bitmap[i] & 1) == 0)
                return ans;
            bitmap[i] >>= 1;
            ans++;
        }
    }
    return ans;
}

int missingNumber(vector<int> &nums) {
    int ans=nums.size();
    for(int i=0;i<nums.size();i++){
        ans^=i^nums[i];
    }
    return ans;
}