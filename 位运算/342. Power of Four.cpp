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

bool isPowerOfFour(int n) {
//    if (n == 1)
//        return true;
//    if (n & 1)return false;
//    n = n >> 1;
//    while (n > 0) {
//        if (n & 1)
//            break;
//        if ((n & 2) && n != 2)
//            break;
//        if ((n & 2) && n == 2)
//            return true;
//        n = n >> 2;
//    }
    return false;
    return n > 0 && (n & (n - 1)) == 0 && (n&0b10101010101010101010101010101010)==0;

}

int main() {

    cout << isPowerOfFour(0b1010) << endl;
    cout << isPowerOfFour(16) << endl;
}
