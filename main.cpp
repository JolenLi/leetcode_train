//
// Created by Jolen on 2021/6/24.
//
//
// Created by Jolen on 2021/6/23.
//



//// dp


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;

int method(vector<int> nums) {
    int maxi = 0, sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum = max(sum + nums[i], 0);
        maxi = max(maxi, sum);
        cout << i << " " << maxi << endl;
    }
    cout << maxi << endl;
    for (int i = 0; i < nums.size() - 1; i++) {
        sum = max(sum + nums[i], nums[i]);
        maxi = max(maxi, sum);
    }
    return maxi;
}

int main() {
    vector<int> nums = {5, -3, 5};
    cout << method(nums) << endl;
}