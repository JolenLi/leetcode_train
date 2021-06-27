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

bool hasAlternatingBits(int n) {
    if (n < 2)
        return true;
    bool bit = n & 1;
    n = n >> 1;
    while (n) {
        if (!((n & 1) ^ bit))
            return false;
        bit = !bit;
        n = n >> 1;
    }
    return true;
}

int main() {

    cout << hasAlternatingBits(6) << endl;
}
