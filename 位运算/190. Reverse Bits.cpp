//
// Created by Jolen on 2021/6/26.
//

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

uint32_t reverseBits(uint32_t n) {
    int SIZE = sizeof(uint32_t) * 8;
    uint32_t ans = 0;
    for (int i = 0; i < SIZE; i++) {
        ans = (ans << 1) + (n & 1);
        n >>= 1;
    }
    return ans;
}

int main() {
    cout << reverseBits(43261596) << endl;
}
