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

int hammingDistance(int x, int y) {
    int z = x ^y;
    int cnt = 0;
    cout << z << endl;
    while (z != 0) {
//        if (z & 1)
//            cnt++;
//        z = z >> 1;
        z = z&(z-1);
        cnt++;
    }
    return cnt;
}


int main() {
    cout << hammingDistance(1, 4) << endl;
}
