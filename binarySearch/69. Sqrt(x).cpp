

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
    int lo = 0, hi = x;
    while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
        long long multi = (long long) mid * mid;
        if (multi == x)
            return mid;
        else if (multi < x)
            lo = mid + 1;
        else if (multi > x)
            hi = mid - 1;
    }
    return hi;
}

int main() {
    cout << mySqrt(9) << endl;
}