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
    return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
}

int main() {

    cout << isPowerOfFour(0b1010) << endl;
    cout << isPowerOfFour(16) << endl;
}
