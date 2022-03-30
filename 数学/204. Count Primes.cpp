//
// Created by Jolen on 2022/3/29.
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
int SIZE = sizeof(int) * 8;

int countPrimes(int n) {
    vector<int> bitMap(n / SIZE + 1, 0);
    int count = 0;
    for (int i = 2; i < n; i++)
        if ((bitMap[i / SIZE] & 1 << (i & 31)) == 0) {
            count++;
            for (int j = 2 * i; j < n; j += i)
                bitMap[j / SIZE] |= 1 << (j & 31);
        }

    return count;
}