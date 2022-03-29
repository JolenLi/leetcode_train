//
// Created by Jolen on 2021/6/20.
//
#include<iostream>
#include<vector>

using namespace std;

int removeElement(vector<int> &nums, int val) {
    int left = 0, right = nums.size();
    while (left < right) {
        if (nums[left] == val) {
            nums[left] = nums[right - 1];
            right--;
        } else {
            left++;
        }
    }
    return left;

}

int main() {
    vector<int> nums = {2, 3, 3, 2};
    int a = removeElement(nums, 2);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i];
    cout << endl;
    cout << a << endl;
    return 0;
}
