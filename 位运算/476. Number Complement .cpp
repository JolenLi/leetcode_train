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

#include <bitset>

using namespace std;

int findComplement(int num) {
    int cnt = 0, temp = num;

    while (temp) {
        cnt++;
        temp = temp >> 1;
    }
    std::bitset<33> x(num);
    std::cout << x << '\n';

    int max = (1 << cnt) - 1;

    return num ^ max;
}

int main() {
    cout << findComplement(2147483647) << endl;
}
