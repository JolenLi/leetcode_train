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

bool isPowerOfTwo(int n) {
    return (n & (n - 1)) == 0 && n > 0;
}


int main() {
    cout << isPowerOfTwo(2) << endl;
}
