//
// Created by Jolen on 2021/6/20.
//
#include<iostream>
#include<vector>

using namespace std;


int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) {
        return n;
    }
    int slow = 2, fast = 2;
    while (fast < n) {
        if (nums[slow - 2] != nums[fast]) {
            nums[slow] = nums[fast];
            ++slow;
        }
        ++fast;

    }
    return slow;
}


//
//int removeDuplicates(vector<int> &nums) {
//    int dis = 0;
//    bool sameTwice = false;
//    int last = nums[0];
//    for (int i = 1; i < nums.size(); i++) {
//        if (nums[i] == last) {
//            if (sameTwice)
//                dis++;
//            else {
//                nums[i - dis] = nums[i];
//                sameTwice = true;
//            }
//        } else {
//            last = nums[i];
//            nums[i - dis] = nums[i];
//            sameTwice = false;
//        }
//    }
//
//
//    for (int i = 0; i < nums.size(); i++) {
//        cout << nums[i] << " ";
//
//
//    }
//    cout << endl;
//    cout << nums.size() - dis << endl;
//}

int main() {
    vector<int> nums = {2,3, 5,5,5, 6};
    int a = removeDuplicates(nums);
    return 0;
}
