//
// Created by Jolen on 2021/6/26.
//


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;

vector<int> singleNumber(vector<int> &nums) {
    long long diff = 0;
    for (int num:nums)
        diff ^= num;
    diff &= (-diff);
    int a = 0, b = 0;
    for (int num:nums) {
        if (num & diff)
            a ^= num;
        else
            b ^= num;
    }
    return {a, b};
}
