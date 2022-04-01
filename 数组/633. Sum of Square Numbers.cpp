//
// Created by Jolen on 2022/3/31.
//



//
// Created by Jolen on 2022/3/11.
//


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool judgeSquareSum(int c) {
    int lo = 0, hi = sqrt(c);
    while (lo <= hi) {
        long long ans = (long long)lo * lo + (long long)hi * hi;
        if (c==ans)
            return true;
        else if(ans>c)
            hi--;
        else if(ans<c)
            lo++;
    }
    return false;
}

int main() {
    cout << isAnagram("cbb", "abc");
}