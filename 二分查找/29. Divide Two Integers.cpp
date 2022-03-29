//
// Created by Jolen on 2022/3/28.
//



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

int divide(int dividend, int divisor) {
    if (divisor == -1 && dividend == INT_MIN)
        return INT_MAX;
    int flag = true;
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
        flag = false;

    int a = dividend < 0 ? dividend : -dividend;
    int b = divisor < 0 ? divisor : -divisor;
    int ans = 0;
    while (a <= b) {
        int c = b;
        int cnt = -1;
        while (c > a - c) {
            c += c;
            cnt += cnt;
        }
        a -= c;
        ans += cnt;
    }
    return flag ? -ans : ans;
}


int main() {
    cout << divide(-2147483648, 1) << endl;
//    cout<<INT_MAX<<endl;
}