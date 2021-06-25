

//
// Created by Jolen on 2021/6/24.
//



//// 二分查找


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;

int mySqrt(int x) {
    int left = 0, right = x, mid;
    while (left < right) {
        mid = left+(1+(right-left) >> 1);
        if ((long long) mid * mid > x) {
            right = mid - 1;
        } else {
            left = mid;
        }
    }
    return left;
}


int main() {
    cout << mySqrt(9) << endl;
}